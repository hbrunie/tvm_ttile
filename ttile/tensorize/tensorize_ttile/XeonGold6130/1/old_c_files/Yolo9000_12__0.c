#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (4, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (1, x);
  T (1, f); T (8, f)]
*/
IND_TYPE c, cp_0, c546_p_0, cp_1, c546, f, fp_0, f662_p_0, f663_p_0, fp_1, f662_p_1, fp_2, f662, f663, h, hp_0, x, xp_0, x547_p_0, xp_1, x547, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y397 = 0;
IND_TYPE x548 = 0;
IND_TYPE h338 = 0;
IND_TYPE w = 0;
IND_TYPE c547 = 0;
IND_TYPE f664 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8033 ,mem_vec_8034 ,mem_vec_8035 ,mem_vec_8036 ,mem_vec_8037 ,mem_vec_8038 ,mem_vec_8039 ,mem_vec_8040 ,mem_vec_8041 ,mem_vec_8042 ,mem_vec_8043 ,mem_vec_8044 ,mem_vec_8045 ,mem_vec_8046 ,mem_vec_8047 ,mem_vec_8048 ,mem_vec_8049 ,mem_vec_8050 ,mem_vec_8051 ,mem_vec_8052 ,mem_vec_8053 ,mem_vec_8054 ,mem_vec_8055 ,mem_vec_8056 ,mem_vec_8057 ,mem_vec_8058 ,mem_vec_8059 ,mem_vec_8060 ,mem_vec_8061 ,mem_vec_8062 ,mem_vec_8063 ,mem_vec_8064 ,mem_vec_8065 ,mem_vec_8066 ,mem_vec_8067 ,mem_vec_8068 ,mem_vec_8069 ,mem_vec_8070 ,mem_vec_8071 ,mem_vec_8072 ,mem_vec_8073 ,mem_vec_8074 ,mem_vec_8075 ,mem_vec_8076 ,mem_vec_8077 ,mem_vec_8078 ,mem_vec_8079 ,mem_vec_8080 ,mem_vec_8081 ,mem_vec_8082 ,mem_vec_8083 ,mem_vec_8084 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 8) (512 / 64)
for (f663 = f664, f663_p_0 = 0;
	f663 < f664 + 512;
	f663 += 64, f663_p_0 += 64){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
	// T (f, 1) (64 / 64)
	for (f662 = f663, f662_p_1 = f663_p_0, f662_p_0 = 0;
		f662 < f663 + 64;
		f662 += 64, f662_p_1 += 64, f662_p_0 += 64){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
		// T (x, 1) (34 / 34)
		for (x547 = x548, x547_p_0 = 0;
			x547 < x548 + 34;
			x547 += 34, x547_p_0 += 34){
				for (y = y397, yp_0 = 0;
					y < y397 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
					// T (f, 1) (64 / 64)
					for (f = f662, fp_2 = f662_p_1, fp_1 = f662_p_0, fp_0 = 0;
						f < f662 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c546 = c547, c546_p_0 = 0;
							c546 < c547 + 256;
							c546 += 64, c546_p_0 += 64){
							// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
							// T (h, 3) (3 / 1)
							for (h = h338, hp_0 = 0;
								h < h338 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 64, f = 64
								// T (x, 34) (34 / 1)
								for (x = x547, xp_1 = x547_p_0, xp_0 = 0;
									x < x547 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8033 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8034 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8035 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_8036 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_8037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_8040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_8041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_8044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_8045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_8048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_8049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_8052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_8053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_8055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_8056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c546, cp_1 = c546_p_0, cp_0 = 0;
												c < c546 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8033);
												mem_vec_8033 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8034);
												mem_vec_8034 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8035);
												mem_vec_8035 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8036);
												mem_vec_8036 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8037);
												mem_vec_8037 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8038);
												mem_vec_8038 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8039);
												mem_vec_8039 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8040);
												mem_vec_8040 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8041);
												mem_vec_8041 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8042);
												mem_vec_8042 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8043);
												mem_vec_8043 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8044);
												mem_vec_8044 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8045);
												mem_vec_8045 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8046);
												mem_vec_8046 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8047);
												mem_vec_8047 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_8048);
												mem_vec_8048 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_8049);
												mem_vec_8049 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_8050);
												mem_vec_8050 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_8051);
												mem_vec_8051 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_8052);
												mem_vec_8052 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8053);
												mem_vec_8053 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8054);
												mem_vec_8054 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_8055);
												mem_vec_8055 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_8056);
												mem_vec_8056 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_8033);
												mem_vec_8033 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_8034);
												mem_vec_8034 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_8035);
												mem_vec_8035 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_8036);
												mem_vec_8036 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_8037);
												mem_vec_8037 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_8038);
												mem_vec_8038 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_8039);
												mem_vec_8039 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_8040);
												mem_vec_8040 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_8041);
												mem_vec_8041 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_8042);
												mem_vec_8042 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_8043);
												mem_vec_8043 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_8044);
												mem_vec_8044 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_8045);
												mem_vec_8045 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_8046);
												mem_vec_8046 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_8047);
												mem_vec_8047 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_8048);
												mem_vec_8048 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_8049);
												mem_vec_8049 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_8050);
												mem_vec_8050 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_8051);
												mem_vec_8051 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_8052);
												mem_vec_8052 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_8053);
												mem_vec_8053 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_8054);
												mem_vec_8054 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_8055);
												mem_vec_8055 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_8056);
												mem_vec_8056 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_8033);
												mem_vec_8033 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_8034);
												mem_vec_8034 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_8035);
												mem_vec_8035 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_8036);
												mem_vec_8036 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_8037);
												mem_vec_8037 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_8038);
												mem_vec_8038 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_8039);
												mem_vec_8039 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_8040);
												mem_vec_8040 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_8041);
												mem_vec_8041 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_8042);
												mem_vec_8042 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_8043);
												mem_vec_8043 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_8044);
												mem_vec_8044 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_8045);
												mem_vec_8045 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_8046);
												mem_vec_8046 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_8047);
												mem_vec_8047 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_8048);
												mem_vec_8048 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_8049);
												mem_vec_8049 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_8050);
												mem_vec_8050 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_8051);
												mem_vec_8051 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_8052);
												mem_vec_8052 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_8053);
												mem_vec_8053 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_8054);
												mem_vec_8054 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_8055);
												mem_vec_8055 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_8056);
												mem_vec_8056 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8033);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8034);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8035);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8036);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8037);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8038);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8039);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8040);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8041);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8042);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8043);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8044);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8045);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8046);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8047);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8048);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8049);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8050);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_8051);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_8052);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8053);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8054);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_8055);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_8056);
								}
							}
						}
					}
				}
				for (y = y397 + 6, yp_0 = 0;
					y < y397 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
					// T (f, 1) (64 / 64)
					for (f = f662, fp_2 = f662_p_1, fp_1 = f662_p_0, fp_0 = 0;
						f < f662 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
						// T (c, 4) (256 / 64)
						for (c546 = c547, c546_p_0 = 0;
							c546 < c547 + 256;
							c546 += 64, c546_p_0 += 64){
							// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
							// T (h, 3) (3 / 1)
							for (h = h338, hp_0 = 0;
								h < h338 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 64, f = 64
								// T (x, 34) (34 / 1)
								for (x = x547, xp_1 = x547_p_0, xp_0 = 0;
									x < x547 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8057 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8058 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8059 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_8060 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_8061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_8064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_8065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_8068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_8069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_8072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_8073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_8076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_8077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_8079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_8080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_8081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_8083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_8084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c546, cp_1 = c546_p_0, cp_0 = 0;
												c < c546 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8057);
												mem_vec_8057 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8058);
												mem_vec_8058 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8059);
												mem_vec_8059 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8060);
												mem_vec_8060 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8061);
												mem_vec_8061 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8062);
												mem_vec_8062 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8063);
												mem_vec_8063 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8064);
												mem_vec_8064 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8065);
												mem_vec_8065 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8066);
												mem_vec_8066 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8067);
												mem_vec_8067 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8068);
												mem_vec_8068 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8069);
												mem_vec_8069 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8070);
												mem_vec_8070 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8071);
												mem_vec_8071 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_8072);
												mem_vec_8072 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_8073);
												mem_vec_8073 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_8074);
												mem_vec_8074 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_8075);
												mem_vec_8075 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_8076);
												mem_vec_8076 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8077);
												mem_vec_8077 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8078);
												mem_vec_8078 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_8079);
												mem_vec_8079 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_8080);
												mem_vec_8080 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_8081);
												mem_vec_8081 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_8082);
												mem_vec_8082 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_8083);
												mem_vec_8083 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_8084);
												mem_vec_8084 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_8057);
												mem_vec_8057 = vec_39;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_8058);
												mem_vec_8058 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_8059);
												mem_vec_8059 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_8060);
												mem_vec_8060 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_8061);
												mem_vec_8061 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_8062);
												mem_vec_8062 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_8063);
												mem_vec_8063 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_8064);
												mem_vec_8064 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_8065);
												mem_vec_8065 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_8066);
												mem_vec_8066 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_8067);
												mem_vec_8067 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_8068);
												mem_vec_8068 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_8069);
												mem_vec_8069 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_8070);
												mem_vec_8070 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_8071);
												mem_vec_8071 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_8072);
												mem_vec_8072 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_8073);
												mem_vec_8073 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_8074);
												mem_vec_8074 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_8075);
												mem_vec_8075 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_8076);
												mem_vec_8076 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);


												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_8077);
												mem_vec_8077 = vec_68;



												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_8078);
												mem_vec_8078 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_8079);
												mem_vec_8079 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_8080);
												mem_vec_8080 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm512_set1_ps(scal_13);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_8081);
												mem_vec_8081 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_8082);
												mem_vec_8082 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_8083);
												mem_vec_8083 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_8084);
												mem_vec_8084 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_8057);
												mem_vec_8057 = vec_78;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_8058);
												mem_vec_8058 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_8059);
												mem_vec_8059 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_8060);
												mem_vec_8060 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_8061);
												mem_vec_8061 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_8062);
												mem_vec_8062 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_8063);
												mem_vec_8063 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_8064);
												mem_vec_8064 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_8065);
												mem_vec_8065 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_8066);
												mem_vec_8066 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_8067);
												mem_vec_8067 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_8068);
												mem_vec_8068 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_8069);
												mem_vec_8069 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_8070);
												mem_vec_8070 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_8071);
												mem_vec_8071 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_8072);
												mem_vec_8072 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm512_set1_ps(scal_18);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_8073);
												mem_vec_8073 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_8074);
												mem_vec_8074 = vec_104;



												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_8075);
												mem_vec_8075 = vec_105;



												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_8076);
												mem_vec_8076 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm512_set1_ps(scal_19);


												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_8077);
												mem_vec_8077 = vec_107;



												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_8078);
												mem_vec_8078 = vec_109;



												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_8079);
												mem_vec_8079 = vec_110;



												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_8080);
												mem_vec_8080 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm512_set1_ps(scal_20);


												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_8081);
												mem_vec_8081 = vec_112;



												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_8082);
												mem_vec_8082 = vec_114;



												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_8083);
												mem_vec_8083 = vec_115;



												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_8084);
												mem_vec_8084 = vec_116;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8057);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8058);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8059);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8060);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8061);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8062);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8063);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8064);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8065);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8066);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8067);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8068);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8069);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8070);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8071);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8072);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8073);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8074);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_8075);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_8076);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8077);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8078);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_8079);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_8080);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8081);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8082);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_8083);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_8084);
								}
							}
						}
					}
				}
		}
	}
}


}