#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (4, y); U (3, h); U (3, w); T (3, c); Hoist_vars [c];
  T (1, x); T (34, y); T (4, x); T (4, y); T (2, f); T (136, x)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x138_p_0, x139_p_0, xp_1, x138_p_1, xp_2, x138, x139, y, yp_0, y114_p_0, yp_1, y114;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y115 = 0;
IND_TYPE x140 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c72 = 0;
IND_TYPE f54 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (x, 136) (544 / 4)
for (x139 = x140, x139_p_0 = 0;
	x139 < x140 + 544;
	x139 += 4, x139_p_0 += 4){
	// y = 544, x = 4, h = 3, w = 3, c = 3, f = 32
	// T (f, 2) (32 / 16)
	for (f = f54, fp_0 = 0;
		f < f54 + 32;
		f += 16, fp_0 += 16){
		// y = 544, x = 4, h = 3, w = 3, c = 3, f = 16
		// T (y, 4) (544 / 136)
		for (y114 = y115, y114_p_0 = 0;
			y114 < y115 + 544;
			y114 += 136, y114_p_0 += 136){
			// y = 136, x = 4, h = 3, w = 3, c = 3, f = 16
			// T (x, 4) (4 / 1)
			for (x138 = x139, x138_p_1 = x139_p_0, x138_p_0 = 0;
				x138 < x139 + 4;
				x138 += 1, x138_p_1 += 1, x138_p_0 += 1){
				// y = 136, x = 1, h = 3, w = 3, c = 3, f = 16
				// T (y, 34) (136 / 4)
				for (y = y114, yp_1 = y114_p_0, yp_0 = 0;
					y < y114 + 136;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = 4, x = 1, h = 3, w = 3, c = 3, f = 16
					// T (x, 1) (1 / 1)
					for (x = x138, xp_2 = x138_p_1, xp_1 = x138_p_0, xp_0 = 0;
						x < x138 + 1;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_328 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								// y = 4, x = 1, h = 3, w = 3, c = 3, f = 16
								// T (c, 3) (3 / 1)
								for (c = c72, cp_0 = 0;
									c < c72 + 3;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_328);
									mem_vec_328 = vec_0;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_4 = _mm512_set1_ps(scal_1);


									vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_329);
									mem_vec_329 = vec_3;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_6 = _mm512_set1_ps(scal_2);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_330);
									mem_vec_330 = vec_5;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_8 = _mm512_set1_ps(scal_3);


									vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_331);
									mem_vec_331 = vec_7;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
									vec_10 = _mm512_set1_ps(scal_4);
									vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

									vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_328);
									mem_vec_328 = vec_9;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
									vec_13 = _mm512_set1_ps(scal_5);


									vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_329);
									mem_vec_329 = vec_12;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
									vec_15 = _mm512_set1_ps(scal_6);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_330);
									mem_vec_330 = vec_14;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
									vec_17 = _mm512_set1_ps(scal_7);


									vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_331);
									mem_vec_331 = vec_16;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
									vec_19 = _mm512_set1_ps(scal_8);
									vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

									vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_328);
									mem_vec_328 = vec_18;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
									vec_22 = _mm512_set1_ps(scal_9);


									vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_329);
									mem_vec_329 = vec_21;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
									vec_24 = _mm512_set1_ps(scal_10);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_330);
									mem_vec_330 = vec_23;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
									vec_26 = _mm512_set1_ps(scal_11);


									vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_331);
									mem_vec_331 = vec_25;
									scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
									vec_28 = _mm512_set1_ps(scal_12);
									vec_29 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_27 = _mm512_fmadd_ps(vec_28, vec_29, mem_vec_328);
									mem_vec_328 = vec_27;
									scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
									vec_31 = _mm512_set1_ps(scal_13);


									vec_30 = _mm512_fmadd_ps(vec_31, vec_29, mem_vec_329);
									mem_vec_329 = vec_30;
									scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
									vec_33 = _mm512_set1_ps(scal_14);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_29, mem_vec_330);
									mem_vec_330 = vec_32;
									scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
									vec_35 = _mm512_set1_ps(scal_15);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_29, mem_vec_331);
									mem_vec_331 = vec_34;
									scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
									vec_37 = _mm512_set1_ps(scal_16);
									vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

									vec_36 = _mm512_fmadd_ps(vec_37, vec_38, mem_vec_328);
									mem_vec_328 = vec_36;
									scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
									vec_40 = _mm512_set1_ps(scal_17);


									vec_39 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_329);
									mem_vec_329 = vec_39;
									scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
									vec_42 = _mm512_set1_ps(scal_18);


									vec_41 = _mm512_fmadd_ps(vec_42, vec_38, mem_vec_330);
									mem_vec_330 = vec_41;
									scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
									vec_44 = _mm512_set1_ps(scal_19);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_331);
									mem_vec_331 = vec_43;
									scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
									vec_46 = _mm512_set1_ps(scal_20);
									vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

									vec_45 = _mm512_fmadd_ps(vec_46, vec_47, mem_vec_328);
									mem_vec_328 = vec_45;
									scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
									vec_49 = _mm512_set1_ps(scal_21);


									vec_48 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_329);
									mem_vec_329 = vec_48;
									scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
									vec_51 = _mm512_set1_ps(scal_22);


									vec_50 = _mm512_fmadd_ps(vec_51, vec_47, mem_vec_330);
									mem_vec_330 = vec_50;
									scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
									vec_53 = _mm512_set1_ps(scal_23);


									vec_52 = _mm512_fmadd_ps(vec_53, vec_47, mem_vec_331);
									mem_vec_331 = vec_52;
									scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
									vec_55 = _mm512_set1_ps(scal_24);
									vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_54 = _mm512_fmadd_ps(vec_55, vec_56, mem_vec_328);
									mem_vec_328 = vec_54;
									scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
									vec_58 = _mm512_set1_ps(scal_25);


									vec_57 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_329);
									mem_vec_329 = vec_57;
									scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
									vec_60 = _mm512_set1_ps(scal_26);


									vec_59 = _mm512_fmadd_ps(vec_60, vec_56, mem_vec_330);
									mem_vec_330 = vec_59;
									scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
									vec_62 = _mm512_set1_ps(scal_27);


									vec_61 = _mm512_fmadd_ps(vec_62, vec_56, mem_vec_331);
									mem_vec_331 = vec_61;
									scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
									vec_64 = _mm512_set1_ps(scal_28);
									vec_65 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

									vec_63 = _mm512_fmadd_ps(vec_64, vec_65, mem_vec_328);
									mem_vec_328 = vec_63;
									scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
									vec_67 = _mm512_set1_ps(scal_29);


									vec_66 = _mm512_fmadd_ps(vec_67, vec_65, mem_vec_329);
									mem_vec_329 = vec_66;
									scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
									vec_69 = _mm512_set1_ps(scal_30);


									vec_68 = _mm512_fmadd_ps(vec_69, vec_65, mem_vec_330);
									mem_vec_330 = vec_68;
									scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
									vec_71 = _mm512_set1_ps(scal_31);


									vec_70 = _mm512_fmadd_ps(vec_71, vec_65, mem_vec_331);
									mem_vec_331 = vec_70;
									scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
									vec_73 = _mm512_set1_ps(scal_32);
									vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

									vec_72 = _mm512_fmadd_ps(vec_73, vec_74, mem_vec_328);
									mem_vec_328 = vec_72;
									scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
									vec_76 = _mm512_set1_ps(scal_33);


									vec_75 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_329);
									mem_vec_329 = vec_75;
									scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
									vec_78 = _mm512_set1_ps(scal_34);


									vec_77 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_330);
									mem_vec_330 = vec_77;
									scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
									vec_80 = _mm512_set1_ps(scal_35);


									vec_79 = _mm512_fmadd_ps(vec_80, vec_74, mem_vec_331);
									mem_vec_331 = vec_79;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_328);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_329);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_330);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_331);
					}
				}
			}
		}
	}
}


}