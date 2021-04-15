#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (4, x);
  T (3, h); T (28, x);
  Lambda_apply y [((Iter 5), (Arg 8)); ((Iter 8), (Arg 9))]; T (8, c);
  T (1, x)]
*/
IND_TYPE c, cp_0, c730_p_0, cp_1, c730, h, hp_0, x, xp_0, x976_p_0, x977_p_0, xp_1, x976_p_1, xp_2, x976, x977, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y488 = 0;
IND_TYPE x978 = 0;
IND_TYPE h324 = 0;
IND_TYPE w = 0;
IND_TYPE c731 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7086 ,mem_vec_7087 ,mem_vec_7088 ,mem_vec_7089 ,mem_vec_7090 ,mem_vec_7091 ,mem_vec_7092 ,mem_vec_7093 ,mem_vec_7094 ,mem_vec_7095 ,mem_vec_7096 ,mem_vec_7097 ,mem_vec_7098 ,mem_vec_7099 ,mem_vec_7100 ,mem_vec_7101 ,mem_vec_7102 ,mem_vec_7103 ,mem_vec_7104 ,mem_vec_7105 ,mem_vec_7106 ,mem_vec_7107 ,mem_vec_7108 ,mem_vec_7109 ,mem_vec_7110 ,mem_vec_7111 ,mem_vec_7112 ,mem_vec_7113 ,mem_vec_7114 ,mem_vec_7115 ,mem_vec_7116 ,mem_vec_7117 ,mem_vec_7118 ,mem_vec_7119 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 1) (112 / 112)
for (x977 = x978, x977_p_0 = 0;
	x977 < x978 + 112;
	x977 += 112, x977_p_0 += 112){
	// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
	// T (c, 8) (32 / 4)
	for (c730 = c731, c730_p_0 = 0;
		c730 < c731 + 32;
		c730 += 4, c730_p_0 += 4){
			for (y = y488, yp_0 = 0;
				y < y488 + 40;
				y += 8, yp_0 += 8){
				// y = ph_y, x = 112, h = 3, w = 3, c = 4, f = 32
				// T (x, 28) (112 / 4)
				for (x976 = x977, x976_p_1 = x977_p_0, x976_p_0 = 0;
					x976 < x977 + 112;
					x976 += 4, x976_p_1 += 4, x976_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h324, hp_0 = 0;
						h < h324 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 4, f = 32
						// T (x, 4) (4 / 1)
						for (x = x976, xp_2 = x976_p_1, xp_1 = x976_p_0, xp_0 = 0;
							x < x976 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_7086 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7087 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_7093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_7094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_7095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_7096 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_7097 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_7098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_7099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_7100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_7101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c730, cp_1 = c730_p_0, cp_0 = 0;
										c < c730 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7086);
										mem_vec_7086 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7087);
										mem_vec_7087 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7088);
										mem_vec_7088 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7089);
										mem_vec_7089 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7090);
										mem_vec_7090 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7091);
										mem_vec_7091 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7092);
										mem_vec_7092 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7093);
										mem_vec_7093 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7094);
										mem_vec_7094 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7095);
										mem_vec_7095 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7096);
										mem_vec_7096 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7097);
										mem_vec_7097 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7098);
										mem_vec_7098 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7099);
										mem_vec_7099 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7100);
										mem_vec_7100 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7101);
										mem_vec_7101 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_7086);
										mem_vec_7086 = vec_26;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_7087);
										mem_vec_7087 = vec_29;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_7088);
										mem_vec_7088 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_7089);
										mem_vec_7089 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_7090);
										mem_vec_7090 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_7091);
										mem_vec_7091 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_7092);
										mem_vec_7092 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_7093);
										mem_vec_7093 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_7094);
										mem_vec_7094 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_7095);
										mem_vec_7095 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7096);
										mem_vec_7096 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7097);
										mem_vec_7097 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_7098);
										mem_vec_7098 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_7099);
										mem_vec_7099 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_7100);
										mem_vec_7100 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_7101);
										mem_vec_7101 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);
										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_7086);
										mem_vec_7086 = vec_52;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_7087);
										mem_vec_7087 = vec_55;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_7088);
										mem_vec_7088 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_7089);
										mem_vec_7089 = vec_59;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_61 = _mm512_set1_ps(scal_18);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_7090);
										mem_vec_7090 = vec_60;



										vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_7091);
										mem_vec_7091 = vec_62;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_7092);
										mem_vec_7092 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_7093);
										mem_vec_7093 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_7094);
										mem_vec_7094 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_7095);
										mem_vec_7095 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_7096);
										mem_vec_7096 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_7097);
										mem_vec_7097 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_7098);
										mem_vec_7098 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_7099);
										mem_vec_7099 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_7100);
										mem_vec_7100 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_7101);
										mem_vec_7101 = vec_77;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7086);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7087);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7088);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7089);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7090);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7091);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7092);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7093);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7094);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7095);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7096);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7097);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7098);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7099);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7100);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7101);
						}
					}
				}
			}
			for (y = y488 + 40, yp_0 = 0;
				y < y488 + 40 + 72;
				y += 9, yp_0 += 9){
				// y = ph_y, x = 112, h = 3, w = 3, c = 4, f = 32
				// T (x, 28) (112 / 4)
				for (x976 = x977, x976_p_1 = x977_p_0, x976_p_0 = 0;
					x976 < x977 + 112;
					x976 += 4, x976_p_1 += 4, x976_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h324, hp_0 = 0;
						h < h324 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 4, f = 32
						// T (x, 4) (4 / 1)
						for (x = x976, xp_2 = x976_p_1, xp_1 = x976_p_0, xp_0 = 0;
							x < x976 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_7102 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7103 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_7109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_7110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_7111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_7112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_7113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_7114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_7115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_7116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_7117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_7118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_7119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c730, cp_1 = c730_p_0, cp_0 = 0;
										c < c730 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7102);
										mem_vec_7102 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7103);
										mem_vec_7103 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7104);
										mem_vec_7104 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7105);
										mem_vec_7105 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7106);
										mem_vec_7106 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7107);
										mem_vec_7107 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7108);
										mem_vec_7108 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7109);
										mem_vec_7109 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7110);
										mem_vec_7110 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7111);
										mem_vec_7111 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7112);
										mem_vec_7112 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7113);
										mem_vec_7113 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7114);
										mem_vec_7114 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7115);
										mem_vec_7115 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7116);
										mem_vec_7116 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7117);
										mem_vec_7117 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7118);
										mem_vec_7118 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7119);
										mem_vec_7119 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);
										vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_7102);
										mem_vec_7102 = vec_29;

										vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_7103);
										mem_vec_7103 = vec_32;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_7104);
										mem_vec_7104 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_7105);
										mem_vec_7105 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_7106);
										mem_vec_7106 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_7107);
										mem_vec_7107 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_7108);
										mem_vec_7108 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_7109);
										mem_vec_7109 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_7110);
										mem_vec_7110 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_7111);
										mem_vec_7111 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_7112);
										mem_vec_7112 = vec_46;



										vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_7113);
										mem_vec_7113 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_7114);
										mem_vec_7114 = vec_49;



										vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_7115);
										mem_vec_7115 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_7116);
										mem_vec_7116 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_7117);
										mem_vec_7117 = vec_54;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
										vec_56 = _mm512_set1_ps(scal_17);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_7118);
										mem_vec_7118 = vec_55;



										vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_7119);
										mem_vec_7119 = vec_57;
										scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_59 = _mm512_set1_ps(scal_18);
										vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_7102);
										mem_vec_7102 = vec_58;

										vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_7103);
										mem_vec_7103 = vec_61;
										scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_7104);
										mem_vec_7104 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_7105);
										mem_vec_7105 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_7106);
										mem_vec_7106 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_7107);
										mem_vec_7107 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_70 = _mm512_set1_ps(scal_21);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_7108);
										mem_vec_7108 = vec_69;



										vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_7109);
										mem_vec_7109 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_73 = _mm512_set1_ps(scal_22);


										vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_7110);
										mem_vec_7110 = vec_72;



										vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_7111);
										mem_vec_7111 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);


										vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_7112);
										mem_vec_7112 = vec_75;



										vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_7113);
										mem_vec_7113 = vec_77;
										scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
										vec_79 = _mm512_set1_ps(scal_24);


										vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_7114);
										mem_vec_7114 = vec_78;



										vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_7115);
										mem_vec_7115 = vec_80;
										scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
										vec_82 = _mm512_set1_ps(scal_25);


										vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_7116);
										mem_vec_7116 = vec_81;



										vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_7117);
										mem_vec_7117 = vec_83;
										scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
										vec_85 = _mm512_set1_ps(scal_26);


										vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_7118);
										mem_vec_7118 = vec_84;



										vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_7119);
										mem_vec_7119 = vec_86;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7102);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7103);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7104);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7105);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7106);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7107);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7108);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7109);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7110);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7111);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7112);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7113);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7114);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7115);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7116);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7117);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7118);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7119);
						}
					}
				}
			}
	}
}


}