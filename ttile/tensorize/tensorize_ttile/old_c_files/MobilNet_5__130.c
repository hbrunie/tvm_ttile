#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, w); Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))];
  T (4, f); T (8, c); T (1, f); T (2, c); T (14, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1404_p_0, c1405_p_0, cp_1, c1404_p_1, cp_2, c1404, c1405, f, fp_0, f1244_p_0, f1245_p_0, fp_1, f1244_p_1, fp_2, f1244, f1245, w, wp_0, x, xp_0, x1098_p_0, xp_1, x1098, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y732 = 0;
IND_TYPE x1099 = 0;
IND_TYPE h = 0;
IND_TYPE w704 = 0;
IND_TYPE c1406 = 0;
IND_TYPE f1246 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11134 ,mem_vec_11135 ,mem_vec_11136 ,mem_vec_11137 ,mem_vec_11138 ,mem_vec_11139 ,mem_vec_11140 ,mem_vec_11141 ,mem_vec_11142 ,mem_vec_11143 ,mem_vec_11144 ,mem_vec_11145 ,mem_vec_11146 ,mem_vec_11147 ,mem_vec_11148 ,mem_vec_11149 ,mem_vec_11150 ,mem_vec_11151 ,mem_vec_11152 ,mem_vec_11153 ,mem_vec_11154 ,mem_vec_11155 ,mem_vec_11156 ,mem_vec_11157 ,mem_vec_11158 ,mem_vec_11159 ,mem_vec_11160 ,mem_vec_11161 ,mem_vec_11162 ,mem_vec_11163 ,mem_vec_11164 ,mem_vec_11165 ,mem_vec_11166 ,mem_vec_11167 ,mem_vec_11168 ,mem_vec_11169 ,mem_vec_11170 ,mem_vec_11171 ,mem_vec_11172 ,mem_vec_11173 ,mem_vec_11174 ,mem_vec_11175 ,mem_vec_11176 ,mem_vec_11177 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f1245 = f1246, f1245_p_0 = 0;
	f1245 < f1246 + 256;
	f1245 += 256, f1245_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (x, 14) (28 / 2)
	for (x1098 = x1099, x1098_p_0 = 0;
		x1098 < x1099 + 28;
		x1098 += 2, x1098_p_0 += 2){
		// y = 28, x = 2, h = 3, w = 3, c = 256, f = 256
		// T (c, 2) (256 / 128)
		for (c1405 = c1406, c1405_p_0 = 0;
			c1405 < c1406 + 256;
			c1405 += 128, c1405_p_0 += 128){
			// y = 28, x = 2, h = 3, w = 3, c = 128, f = 256
			// T (f, 1) (256 / 256)
			for (f1244 = f1245, f1244_p_1 = f1245_p_0, f1244_p_0 = 0;
				f1244 < f1245 + 256;
				f1244 += 256, f1244_p_1 += 256, f1244_p_0 += 256){
				// y = 28, x = 2, h = 3, w = 3, c = 128, f = 256
				// T (c, 8) (128 / 16)
				for (c1404 = c1405, c1404_p_1 = c1405_p_0, c1404_p_0 = 0;
					c1404 < c1405 + 128;
					c1404 += 16, c1404_p_1 += 16, c1404_p_0 += 16){
					// y = 28, x = 2, h = 3, w = 3, c = 16, f = 256
					// T (f, 4) (256 / 64)
					for (f = f1244, fp_2 = f1244_p_1, fp_1 = f1244_p_0, fp_0 = 0;
						f < f1244 + 256;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							for (y = y732, yp_0 = 0;
								y < y732 + 10;
								y += 5, yp_0 += 5){
								// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
								// T (w, 3) (3 / 1)
								for (w = w704, wp_0 = 0;
									w < w704 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 64
									// T (x, 2) (2 / 1)
									for (x = x1098, xp_1 = x1098_p_0, xp_0 = 0;
										x < x1098 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11134 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11135 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11136 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_11137 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_11138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_11141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_11142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_11145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_11146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_11149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_11150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_11153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
												// T (c, 16) (16 / 1)
												for (c = c1404, cp_2 = c1404_p_1, cp_1 = c1404_p_0, cp_0 = 0;
													c < c1404 + 16;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11134);
													mem_vec_11134 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11135);
													mem_vec_11135 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11136);
													mem_vec_11136 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11137);
													mem_vec_11137 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11138);
													mem_vec_11138 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11139);
													mem_vec_11139 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11140);
													mem_vec_11140 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11141);
													mem_vec_11141 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11142);
													mem_vec_11142 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11143);
													mem_vec_11143 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11144);
													mem_vec_11144 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11145);
													mem_vec_11145 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11146);
													mem_vec_11146 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11147);
													mem_vec_11147 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11148);
													mem_vec_11148 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11149);
													mem_vec_11149 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11150);
													mem_vec_11150 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11151);
													mem_vec_11151 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11152);
													mem_vec_11152 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11153);
													mem_vec_11153 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_30 = _mm512_set1_ps(scal_5);
													vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_11134);
													mem_vec_11134 = vec_29;

													vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_11135);
													mem_vec_11135 = vec_32;

													vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

													vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_11136);
													mem_vec_11136 = vec_34;

													vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

													vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_11137);
													mem_vec_11137 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_39 = _mm512_set1_ps(scal_6);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_11138);
													mem_vec_11138 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_11139);
													mem_vec_11139 = vec_40;



													vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_11140);
													mem_vec_11140 = vec_41;



													vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_11141);
													mem_vec_11141 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm512_set1_ps(scal_7);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_11142);
													mem_vec_11142 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_11143);
													mem_vec_11143 = vec_45;



													vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_11144);
													mem_vec_11144 = vec_46;



													vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_11145);
													mem_vec_11145 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_49 = _mm512_set1_ps(scal_8);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_11146);
													mem_vec_11146 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_11147);
													mem_vec_11147 = vec_50;



													vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_11148);
													mem_vec_11148 = vec_51;



													vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_11149);
													mem_vec_11149 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_54 = _mm512_set1_ps(scal_9);


													vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_11150);
													mem_vec_11150 = vec_53;



													vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_11151);
													mem_vec_11151 = vec_55;



													vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_11152);
													mem_vec_11152 = vec_56;



													vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_11153);
													mem_vec_11153 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_59 = _mm512_set1_ps(scal_10);
													vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_11134);
													mem_vec_11134 = vec_58;

													vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_11135);
													mem_vec_11135 = vec_61;

													vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

													vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_11136);
													mem_vec_11136 = vec_63;

													vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

													vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_11137);
													mem_vec_11137 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_68 = _mm512_set1_ps(scal_11);


													vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_11138);
													mem_vec_11138 = vec_67;



													vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_11139);
													mem_vec_11139 = vec_69;



													vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_11140);
													mem_vec_11140 = vec_70;



													vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_11141);
													mem_vec_11141 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm512_set1_ps(scal_12);


													vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_11142);
													mem_vec_11142 = vec_72;



													vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_11143);
													mem_vec_11143 = vec_74;



													vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_11144);
													mem_vec_11144 = vec_75;



													vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_11145);
													mem_vec_11145 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_78 = _mm512_set1_ps(scal_13);


													vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_11146);
													mem_vec_11146 = vec_77;



													vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_11147);
													mem_vec_11147 = vec_79;



													vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_11148);
													mem_vec_11148 = vec_80;



													vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_11149);
													mem_vec_11149 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_83 = _mm512_set1_ps(scal_14);


													vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_11150);
													mem_vec_11150 = vec_82;



													vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_11151);
													mem_vec_11151 = vec_84;



													vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_11152);
													mem_vec_11152 = vec_85;



													vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_11153);
													mem_vec_11153 = vec_86;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11134);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11135);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11136);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11137);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11138);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11139);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11140);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11141);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11142);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11143);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11144);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11145);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11146);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11147);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11148);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11149);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11150);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11151);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11152);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11153);
									}
								}
							}
							for (y = y732 + 10, yp_0 = 0;
								y < y732 + 10 + 18;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
								// T (w, 3) (3 / 1)
								for (w = w704, wp_0 = 0;
									w < w704 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 64
									// T (x, 2) (2 / 1)
									for (x = x1098, xp_1 = x1098_p_0, xp_0 = 0;
										x < x1098 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11154 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11155 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11156 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_11157 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_11158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_11161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_11162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_11165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_11166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_11169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_11170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_11173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_11174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_11177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
												// T (c, 16) (16 / 1)
												for (c = c1404, cp_2 = c1404_p_1, cp_1 = c1404_p_0, cp_0 = 0;
													c < c1404 + 16;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11154);
													mem_vec_11154 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11155);
													mem_vec_11155 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11156);
													mem_vec_11156 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11157);
													mem_vec_11157 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11158);
													mem_vec_11158 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11159);
													mem_vec_11159 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11160);
													mem_vec_11160 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11161);
													mem_vec_11161 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11162);
													mem_vec_11162 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11163);
													mem_vec_11163 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11164);
													mem_vec_11164 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11165);
													mem_vec_11165 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11166);
													mem_vec_11166 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11167);
													mem_vec_11167 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11168);
													mem_vec_11168 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11169);
													mem_vec_11169 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11170);
													mem_vec_11170 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11171);
													mem_vec_11171 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11172);
													mem_vec_11172 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11173);
													mem_vec_11173 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11174);
													mem_vec_11174 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11175);
													mem_vec_11175 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_11176);
													mem_vec_11176 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_11177);
													mem_vec_11177 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm512_set1_ps(scal_6);
													vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_11154);
													mem_vec_11154 = vec_34;

													vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_11155);
													mem_vec_11155 = vec_37;

													vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

													vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_11156);
													mem_vec_11156 = vec_39;

													vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

													vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_11157);
													mem_vec_11157 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm512_set1_ps(scal_7);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_11158);
													mem_vec_11158 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_11159);
													mem_vec_11159 = vec_45;



													vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_11160);
													mem_vec_11160 = vec_46;



													vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_11161);
													mem_vec_11161 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm512_set1_ps(scal_8);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_11162);
													mem_vec_11162 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_11163);
													mem_vec_11163 = vec_50;



													vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_11164);
													mem_vec_11164 = vec_51;



													vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_11165);
													mem_vec_11165 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm512_set1_ps(scal_9);


													vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_11166);
													mem_vec_11166 = vec_53;



													vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_11167);
													mem_vec_11167 = vec_55;



													vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_11168);
													mem_vec_11168 = vec_56;



													vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_11169);
													mem_vec_11169 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm512_set1_ps(scal_10);


													vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_11170);
													mem_vec_11170 = vec_58;



													vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_11171);
													mem_vec_11171 = vec_60;



													vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_11172);
													mem_vec_11172 = vec_61;



													vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_11173);
													mem_vec_11173 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm512_set1_ps(scal_11);


													vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_11174);
													mem_vec_11174 = vec_63;



													vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_11175);
													mem_vec_11175 = vec_65;



													vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_11176);
													mem_vec_11176 = vec_66;



													vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_11177);
													mem_vec_11177 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm512_set1_ps(scal_12);
													vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_11154);
													mem_vec_11154 = vec_68;

													vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_11155);
													mem_vec_11155 = vec_71;

													vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

													vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_11156);
													mem_vec_11156 = vec_73;

													vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

													vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_11157);
													mem_vec_11157 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm512_set1_ps(scal_13);


													vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_11158);
													mem_vec_11158 = vec_77;



													vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_11159);
													mem_vec_11159 = vec_79;



													vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_11160);
													mem_vec_11160 = vec_80;



													vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_11161);
													mem_vec_11161 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm512_set1_ps(scal_14);


													vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_11162);
													mem_vec_11162 = vec_82;



													vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_11163);
													mem_vec_11163 = vec_84;



													vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_11164);
													mem_vec_11164 = vec_85;



													vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_11165);
													mem_vec_11165 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm512_set1_ps(scal_15);


													vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_11166);
													mem_vec_11166 = vec_87;



													vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_11167);
													mem_vec_11167 = vec_89;



													vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_11168);
													mem_vec_11168 = vec_90;



													vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_11169);
													mem_vec_11169 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm512_set1_ps(scal_16);


													vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_11170);
													mem_vec_11170 = vec_92;



													vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_11171);
													mem_vec_11171 = vec_94;



													vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_11172);
													mem_vec_11172 = vec_95;



													vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_11173);
													mem_vec_11173 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm512_set1_ps(scal_17);


													vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_11174);
													mem_vec_11174 = vec_97;



													vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_11175);
													mem_vec_11175 = vec_99;



													vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_11176);
													mem_vec_11176 = vec_100;



													vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_11177);
													mem_vec_11177 = vec_101;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11154);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11155);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11156);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11157);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11158);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11159);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11160);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11161);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11162);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11163);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11164);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11165);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11166);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11167);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11168);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11169);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11170);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11171);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11172);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11173);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11174);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11175);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_11176);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_11177);
									}
								}
							}
					}
				}
			}
		}
	}
}


}