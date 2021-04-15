#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (8, c); T (1, y); T (32, f);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]]
*/
IND_TYPE c, cp_0, c411_p_0, cp_1, c411, f, fp_0, w, wp_0, x, xp_0, y, yp_0, y294_p_0, yp_1, y294;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y295 = 0;
IND_TYPE x415 = 0;
IND_TYPE h = 0;
IND_TYPE w175 = 0;
IND_TYPE c412 = 0;
IND_TYPE f508 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6118 ,mem_vec_6119 ,mem_vec_6120 ,mem_vec_6121 ,mem_vec_6122 ,mem_vec_6123 ,mem_vec_6124 ,mem_vec_6125 ,mem_vec_6126 ,mem_vec_6127 ,mem_vec_6128 ,mem_vec_6129 ,mem_vec_6130 ,mem_vec_6131 ,mem_vec_6132 ,mem_vec_6133 ,mem_vec_6134 ,mem_vec_6135 ,mem_vec_6136 ,mem_vec_6137 ,mem_vec_6138 ,mem_vec_6139 ,mem_vec_6140 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_8 ,vec_9;
	for (y294 = y295, y294_p_0 = 0;
		y294 < y295 + 22;
		y294 += 11, y294_p_0 += 11){
		// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
		// T (f, 32) (512 / 16)
		for (f = f508, fp_0 = 0;
			f < f508 + 512;
			f += 16, fp_0 += 16){
			// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 16
			// T (y, 1) (ph_y / ph_y)
			for (y = y294, yp_1 = y294_p_0, yp_0 = 0;
				y < y294 + 11;
				y += 11, yp_1 += 11, yp_0 += 11){
				// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 16
				// T (c, 8) (256 / 32)
				for (c411 = c412, c411_p_0 = 0;
					c411 < c412 + 256;
					c411 += 32, c411_p_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 16
					// T (x, 34) (34 / 1)
					for (x = x415, xp_0 = 0;
						x < x415 + 34;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
						// T (w, 3) (3 / 1)
						for (w = w175, wp_0 = 0;
							w < w175 + 3;
							w += 1, wp_0 += 1){
									mem_vec_6118 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_6124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_6125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_6126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_6127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_6128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
									// T (c, 32) (32 / 1)
									for (c = c411, cp_1 = c411_p_0, cp_0 = 0;
										c < c411 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6118);
										mem_vec_6118 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_6119);
										mem_vec_6119 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6120);
										mem_vec_6120 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_6121);
										mem_vec_6121 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6122);
										mem_vec_6122 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6123);
										mem_vec_6123 = vec_11;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);


										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_6124);
										mem_vec_6124 = vec_13;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);


										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_6125);
										mem_vec_6125 = vec_15;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_18 = _mm512_set1_ps(scal_8);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6126);
										mem_vec_6126 = vec_17;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_20 = _mm512_set1_ps(scal_9);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6127);
										mem_vec_6127 = vec_19;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_22 = _mm512_set1_ps(scal_10);


										vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_6128);
										mem_vec_6128 = vec_21;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_11);
										vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_6118);
										mem_vec_6118 = vec_23;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_27 = _mm512_set1_ps(scal_12);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_25, mem_vec_6119);
										mem_vec_6119 = vec_26;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_13);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_6120);
										mem_vec_6120 = vec_28;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_31 = _mm512_set1_ps(scal_14);


										vec_30 = _mm512_fmadd_ps(vec_31, vec_25, mem_vec_6121);
										mem_vec_6121 = vec_30;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_25, mem_vec_6122);
										mem_vec_6122 = vec_32;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_16);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_6123);
										mem_vec_6123 = vec_34;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_37 = _mm512_set1_ps(scal_17);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_25, mem_vec_6124);
										mem_vec_6124 = vec_36;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_18);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_25, mem_vec_6125);
										mem_vec_6125 = vec_38;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_19);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_6126);
										mem_vec_6126 = vec_40;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_43 = _mm512_set1_ps(scal_20);


										vec_42 = _mm512_fmadd_ps(vec_43, vec_25, mem_vec_6127);
										mem_vec_6127 = vec_42;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
										vec_45 = _mm512_set1_ps(scal_21);


										vec_44 = _mm512_fmadd_ps(vec_45, vec_25, mem_vec_6128);
										mem_vec_6128 = vec_44;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_47 = _mm512_set1_ps(scal_22);
										vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_6118);
										mem_vec_6118 = vec_46;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_50 = _mm512_set1_ps(scal_23);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_48, mem_vec_6119);
										mem_vec_6119 = vec_49;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_52 = _mm512_set1_ps(scal_24);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_6120);
										mem_vec_6120 = vec_51;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_54 = _mm512_set1_ps(scal_25);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_48, mem_vec_6121);
										mem_vec_6121 = vec_53;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_56 = _mm512_set1_ps(scal_26);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_48, mem_vec_6122);
										mem_vec_6122 = vec_55;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_27);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_6123);
										mem_vec_6123 = vec_57;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_60 = _mm512_set1_ps(scal_28);


										vec_59 = _mm512_fmadd_ps(vec_60, vec_48, mem_vec_6124);
										mem_vec_6124 = vec_59;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_62 = _mm512_set1_ps(scal_29);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_48, mem_vec_6125);
										mem_vec_6125 = vec_61;
										scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_64 = _mm512_set1_ps(scal_30);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_6126);
										mem_vec_6126 = vec_63;
										scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_66 = _mm512_set1_ps(scal_31);


										vec_65 = _mm512_fmadd_ps(vec_66, vec_48, mem_vec_6127);
										mem_vec_6127 = vec_65;
										scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_32);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_48, mem_vec_6128);
										mem_vec_6128 = vec_67;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6118);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6119);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6120);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6121);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6122);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6123);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6124);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6125);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6126);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6127);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6128);
						}
					}
				}
			}
		}
	}
	for (y294 = y295 + 22, y294_p_0 = 0;
		y294 < y295 + 22 + 12;
		y294 += 12, y294_p_0 += 12){
		// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
		// T (f, 32) (512 / 16)
		for (f = f508, fp_0 = 0;
			f < f508 + 512;
			f += 16, fp_0 += 16){
			// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 16
			// T (y, 1) (ph_y / ph_y)
			for (y = y294, yp_1 = y294_p_0, yp_0 = 0;
				y < y294 + 12;
				y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 16
				// T (c, 8) (256 / 32)
				for (c411 = c412, c411_p_0 = 0;
					c411 < c412 + 256;
					c411 += 32, c411_p_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 16
					// T (x, 34) (34 / 1)
					for (x = x415, xp_0 = 0;
						x < x415 + 34;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
						// T (w, 3) (3 / 1)
						for (w = w175, wp_0 = 0;
							w < w175 + 3;
							w += 1, wp_0 += 1){
									mem_vec_6129 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_6135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_6136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_6137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_6138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_6139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_6140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
									// T (c, 32) (32 / 1)
									for (c = c411, cp_1 = c411_p_0, cp_0 = 0;
										c < c411 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6129);
										mem_vec_6129 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_6130);
										mem_vec_6130 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6131);
										mem_vec_6131 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_6132);
										mem_vec_6132 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6133);
										mem_vec_6133 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6134);
										mem_vec_6134 = vec_11;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);


										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_6135);
										mem_vec_6135 = vec_13;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);


										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_6136);
										mem_vec_6136 = vec_15;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_18 = _mm512_set1_ps(scal_8);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6137);
										mem_vec_6137 = vec_17;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_20 = _mm512_set1_ps(scal_9);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6138);
										mem_vec_6138 = vec_19;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_22 = _mm512_set1_ps(scal_10);


										vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_6139);
										mem_vec_6139 = vec_21;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_24 = _mm512_set1_ps(scal_11);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6140);
										mem_vec_6140 = vec_23;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_26 = _mm512_set1_ps(scal_12);
										vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_25 = _mm512_fmadd_ps(vec_26, vec_27, mem_vec_6129);
										mem_vec_6129 = vec_25;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_13);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6130);
										mem_vec_6130 = vec_28;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_31 = _mm512_set1_ps(scal_14);


										vec_30 = _mm512_fmadd_ps(vec_31, vec_27, mem_vec_6131);
										mem_vec_6131 = vec_30;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_27, mem_vec_6132);
										mem_vec_6132 = vec_32;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_16);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_6133);
										mem_vec_6133 = vec_34;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_37 = _mm512_set1_ps(scal_17);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_27, mem_vec_6134);
										mem_vec_6134 = vec_36;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_18);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_27, mem_vec_6135);
										mem_vec_6135 = vec_38;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_19);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_6136);
										mem_vec_6136 = vec_40;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
										vec_43 = _mm512_set1_ps(scal_20);


										vec_42 = _mm512_fmadd_ps(vec_43, vec_27, mem_vec_6137);
										mem_vec_6137 = vec_42;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
										vec_45 = _mm512_set1_ps(scal_21);


										vec_44 = _mm512_fmadd_ps(vec_45, vec_27, mem_vec_6138);
										mem_vec_6138 = vec_44;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
										vec_47 = _mm512_set1_ps(scal_22);


										vec_46 = _mm512_fmadd_ps(vec_47, vec_27, mem_vec_6139);
										mem_vec_6139 = vec_46;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
										vec_49 = _mm512_set1_ps(scal_23);


										vec_48 = _mm512_fmadd_ps(vec_49, vec_27, mem_vec_6140);
										mem_vec_6140 = vec_48;
										scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_51 = _mm512_set1_ps(scal_24);
										vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_50 = _mm512_fmadd_ps(vec_51, vec_52, mem_vec_6129);
										mem_vec_6129 = vec_50;
										scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_54 = _mm512_set1_ps(scal_25);


										vec_53 = _mm512_fmadd_ps(vec_54, vec_52, mem_vec_6130);
										mem_vec_6130 = vec_53;
										scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_56 = _mm512_set1_ps(scal_26);


										vec_55 = _mm512_fmadd_ps(vec_56, vec_52, mem_vec_6131);
										mem_vec_6131 = vec_55;
										scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_27);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_6132);
										mem_vec_6132 = vec_57;
										scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_60 = _mm512_set1_ps(scal_28);


										vec_59 = _mm512_fmadd_ps(vec_60, vec_52, mem_vec_6133);
										mem_vec_6133 = vec_59;
										scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_62 = _mm512_set1_ps(scal_29);


										vec_61 = _mm512_fmadd_ps(vec_62, vec_52, mem_vec_6134);
										mem_vec_6134 = vec_61;
										scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_64 = _mm512_set1_ps(scal_30);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_52, mem_vec_6135);
										mem_vec_6135 = vec_63;
										scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_66 = _mm512_set1_ps(scal_31);


										vec_65 = _mm512_fmadd_ps(vec_66, vec_52, mem_vec_6136);
										mem_vec_6136 = vec_65;
										scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_32);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_6137);
										mem_vec_6137 = vec_67;
										scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
										vec_70 = _mm512_set1_ps(scal_33);


										vec_69 = _mm512_fmadd_ps(vec_70, vec_52, mem_vec_6138);
										mem_vec_6138 = vec_69;
										scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
										vec_72 = _mm512_set1_ps(scal_34);


										vec_71 = _mm512_fmadd_ps(vec_72, vec_52, mem_vec_6139);
										mem_vec_6139 = vec_71;
										scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
										vec_74 = _mm512_set1_ps(scal_35);


										vec_73 = _mm512_fmadd_ps(vec_74, vec_52, mem_vec_6140);
										mem_vec_6140 = vec_73;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6129);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6130);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6131);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6132);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6133);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6134);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6135);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6136);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6137);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6138);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6139);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6140);
						}
					}
				}
			}
		}
	}


}