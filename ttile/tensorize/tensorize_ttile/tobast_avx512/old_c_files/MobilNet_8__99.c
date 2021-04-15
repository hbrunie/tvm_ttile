#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (4, c); T (8, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (8, c)]
*/
IND_TYPE c, cp_0, c1296_p_0, c1297_p_0, cp_1, c1296_p_1, cp_2, c1296, c1297, f, fp_0, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y594 = 0;
IND_TYPE x732 = 0;
IND_TYPE h544 = 0;
IND_TYPE w = 0;
IND_TYPE c1298 = 0;
IND_TYPE f900 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6896 ,mem_vec_6897 ,mem_vec_6898 ,mem_vec_6899 ,mem_vec_6900 ,mem_vec_6901 ,mem_vec_6902 ,mem_vec_6903 ,mem_vec_6904 ,mem_vec_6905 ,mem_vec_6906 ,mem_vec_6907 ,mem_vec_6908 ,mem_vec_6909 ,mem_vec_6910 ,mem_vec_6911 ,mem_vec_6912 ,mem_vec_6913 ,mem_vec_6914 ,mem_vec_6915 ,mem_vec_6916 ,mem_vec_6917 ,mem_vec_6918 ,mem_vec_6919 ,mem_vec_6920 ,mem_vec_6921 ,mem_vec_6922 ,mem_vec_6923 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (c, 8) (512 / 64)
for (c1297 = c1298, c1297_p_0 = 0;
	c1297 < c1298 + 512;
	c1297 += 64, c1297_p_0 += 64){
		for (y = y594, yp_0 = 0;
			y < y594 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 512
			// T (f, 8) (512 / 64)
			for (f = f900, fp_0 = 0;
				f < f900 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
				// T (c, 4) (64 / 16)
				for (c1296 = c1297, c1296_p_1 = c1297_p_0, c1296_p_0 = 0;
					c1296 < c1297 + 64;
					c1296 += 16, c1296_p_1 += 16, c1296_p_0 += 16){
					// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
					// T (h, 3) (3 / 1)
					for (h = h544, hp_0 = 0;
						h < h544 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 64
						// T (x, 7) (7 / 1)
						for (x = x732, xp_0 = 0;
							x < x732 + 7;
							x += 1, xp_0 += 1){
									mem_vec_6896 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6897 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6898 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_6899 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_6900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_6903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_6904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_6907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1296, cp_2 = c1296_p_1, cp_1 = c1296_p_0, cp_0 = 0;
										c < c1296 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6896);
										mem_vec_6896 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6897);
										mem_vec_6897 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6898);
										mem_vec_6898 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6899);
										mem_vec_6899 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6900);
										mem_vec_6900 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6901);
										mem_vec_6901 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6902);
										mem_vec_6902 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6903);
										mem_vec_6903 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6904);
										mem_vec_6904 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6905);
										mem_vec_6905 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6906);
										mem_vec_6906 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6907);
										mem_vec_6907 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_6896);
										mem_vec_6896 = vec_19;

										vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_6897);
										mem_vec_6897 = vec_22;

										vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_6898);
										mem_vec_6898 = vec_24;

										vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_6899);
										mem_vec_6899 = vec_26;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_29 = _mm512_set1_ps(scal_4);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_6900);
										mem_vec_6900 = vec_28;



										vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_6901);
										mem_vec_6901 = vec_30;



										vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_6902);
										mem_vec_6902 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6903);
										mem_vec_6903 = vec_32;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_6904);
										mem_vec_6904 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_6905);
										mem_vec_6905 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_6906);
										mem_vec_6906 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_6907);
										mem_vec_6907 = vec_37;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_39 = _mm512_set1_ps(scal_6);
										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_6896);
										mem_vec_6896 = vec_38;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_6897);
										mem_vec_6897 = vec_41;

										vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_6898);
										mem_vec_6898 = vec_43;

										vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_6899);
										mem_vec_6899 = vec_45;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_48 = _mm512_set1_ps(scal_7);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_6900);
										mem_vec_6900 = vec_47;



										vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_6901);
										mem_vec_6901 = vec_49;



										vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_6902);
										mem_vec_6902 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_6903);
										mem_vec_6903 = vec_51;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_53 = _mm512_set1_ps(scal_8);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_6904);
										mem_vec_6904 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_6905);
										mem_vec_6905 = vec_54;



										vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_6906);
										mem_vec_6906 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_6907);
										mem_vec_6907 = vec_56;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6896);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6897);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6898);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6899);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6900);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6901);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6902);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6903);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6904);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6905);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6906);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6907);
						}
					}
				}
			}
		}
		for (y = y594 + 3, yp_0 = 0;
			y < y594 + 3 + 4;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 512
			// T (f, 8) (512 / 64)
			for (f = f900, fp_0 = 0;
				f < f900 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
				// T (c, 4) (64 / 16)
				for (c1296 = c1297, c1296_p_1 = c1297_p_0, c1296_p_0 = 0;
					c1296 < c1297 + 64;
					c1296 += 16, c1296_p_1 += 16, c1296_p_0 += 16){
					// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
					// T (h, 3) (3 / 1)
					for (h = h544, hp_0 = 0;
						h < h544 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 64
						// T (x, 7) (7 / 1)
						for (x = x732, xp_0 = 0;
							x < x732 + 7;
							x += 1, xp_0 += 1){
									mem_vec_6908 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6909 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6910 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_6911 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_6912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_6915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_6916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_6919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_6920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_6922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_6923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1296, cp_2 = c1296_p_1, cp_1 = c1296_p_0, cp_0 = 0;
										c < c1296 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6908);
										mem_vec_6908 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6909);
										mem_vec_6909 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6910);
										mem_vec_6910 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6911);
										mem_vec_6911 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6912);
										mem_vec_6912 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6913);
										mem_vec_6913 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6914);
										mem_vec_6914 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6915);
										mem_vec_6915 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6916);
										mem_vec_6916 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6917);
										mem_vec_6917 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6918);
										mem_vec_6918 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6919);
										mem_vec_6919 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6920);
										mem_vec_6920 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6921);
										mem_vec_6921 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6922);
										mem_vec_6922 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6923);
										mem_vec_6923 = vec_23;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_6908);
										mem_vec_6908 = vec_24;

										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_6909);
										mem_vec_6909 = vec_27;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_6910);
										mem_vec_6910 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_6911);
										mem_vec_6911 = vec_31;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_6912);
										mem_vec_6912 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_6913);
										mem_vec_6913 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_6914);
										mem_vec_6914 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_6915);
										mem_vec_6915 = vec_37;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_6916);
										mem_vec_6916 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_6917);
										mem_vec_6917 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_6918);
										mem_vec_6918 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_6919);
										mem_vec_6919 = vec_42;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_6920);
										mem_vec_6920 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_6921);
										mem_vec_6921 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_6922);
										mem_vec_6922 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_6923);
										mem_vec_6923 = vec_47;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);
										vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_6908);
										mem_vec_6908 = vec_48;

										vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_6909);
										mem_vec_6909 = vec_51;

										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_6910);
										mem_vec_6910 = vec_53;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_6911);
										mem_vec_6911 = vec_55;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_58 = _mm512_set1_ps(scal_9);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_6912);
										mem_vec_6912 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_6913);
										mem_vec_6913 = vec_59;



										vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_6914);
										mem_vec_6914 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_6915);
										mem_vec_6915 = vec_61;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_63 = _mm512_set1_ps(scal_10);


										vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_6916);
										mem_vec_6916 = vec_62;



										vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_6917);
										mem_vec_6917 = vec_64;



										vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_6918);
										mem_vec_6918 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_6919);
										mem_vec_6919 = vec_66;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_6920);
										mem_vec_6920 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_6921);
										mem_vec_6921 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_6922);
										mem_vec_6922 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_6923);
										mem_vec_6923 = vec_71;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6908);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6909);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6910);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6911);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6912);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6913);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6914);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6915);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6916);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6917);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6918);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6919);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6920);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6921);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6922);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6923);
						}
					}
				}
			}
		}
}


}