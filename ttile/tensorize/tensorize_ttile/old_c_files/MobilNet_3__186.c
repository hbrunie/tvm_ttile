#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 11)); ((Iter 3), (Arg 15))]; T (4, f);
  T (128, c); T (56, x)]
*/
IND_TYPE c, cp_0, c510_p_0, cp_1, c510, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x648_p_0, x649_p_0, xp_1, x648_p_1, xp_2, x648, x649, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y340 = 0;
IND_TYPE x650 = 0;
IND_TYPE h292 = 0;
IND_TYPE w310 = 0;
IND_TYPE c511 = 0;
IND_TYPE f404 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5020 ,mem_vec_5021 ,mem_vec_5022 ,mem_vec_5023 ,mem_vec_5024 ,mem_vec_5025 ,mem_vec_5026 ,mem_vec_5027 ,mem_vec_5028 ,mem_vec_5029 ,mem_vec_5030 ,mem_vec_5031 ,mem_vec_5032 ,mem_vec_5033 ,mem_vec_5034 ,mem_vec_5035 ,mem_vec_5036 ,mem_vec_5037 ,mem_vec_5038 ,mem_vec_5039 ,mem_vec_5040 ,mem_vec_5041 ,mem_vec_5042 ,mem_vec_5043 ,mem_vec_5044 ,mem_vec_5045 ,mem_vec_5046 ,mem_vec_5047 ,mem_vec_5048 ,mem_vec_5049 ,mem_vec_5050 ,mem_vec_5051 ,mem_vec_5052 ,mem_vec_5053 ,mem_vec_5054 ,mem_vec_5055 ,mem_vec_5056 ,mem_vec_5057 ,mem_vec_5058 ,mem_vec_5059 ,mem_vec_5060 ,mem_vec_5061 ,mem_vec_5062 ,mem_vec_5063 ,mem_vec_5064 ,mem_vec_5065 ,mem_vec_5066 ,mem_vec_5067 ,mem_vec_5068 ,mem_vec_5069 ,mem_vec_5070 ,mem_vec_5071 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 56) (56 / 1)
for (x649 = x650, x649_p_0 = 0;
	x649 < x650 + 56;
	x649 += 1, x649_p_0 += 1){
	// y = 56, x = 1, h = 3, w = 3, c = 128, f = 128
	// T (c, 128) (128 / 1)
	for (c510 = c511, c510_p_0 = 0;
		c510 < c511 + 128;
		c510 += 1, c510_p_0 += 1){
		// y = 56, x = 1, h = 3, w = 3, c = 1, f = 128
		// T (f, 4) (128 / 32)
		for (f = f404, fp_0 = 0;
			f < f404 + 128;
			f += 32, fp_0 += 32){
				for (y = y340, yp_0 = 0;
					y < y340 + 11;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
					// T (x, 1) (1 / 1)
					for (x648 = x649, x648_p_1 = x649_p_0, x648_p_0 = 0;
						x648 < x649 + 1;
						x648 += 1, x648_p_1 += 1, x648_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
						// T (h, 3) (3 / 1)
						for (h = h292, hp_0 = 0;
							h < h292 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w310, wp_0 = 0;
								w < w310 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
								// T (x, 1) (1 / 1)
								for (x = x648, xp_2 = x648_p_1, xp_1 = x648_p_0, xp_0 = 0;
									x < x648 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5020 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5021 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_5036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_5038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_5039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_5040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_5041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c510, cp_1 = c510_p_0, cp_0 = 0;
												c < c510 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5020);
												mem_vec_5020 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5021);
												mem_vec_5021 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5022);
												mem_vec_5022 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5023);
												mem_vec_5023 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5024);
												mem_vec_5024 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5025);
												mem_vec_5025 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5026);
												mem_vec_5026 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5027);
												mem_vec_5027 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5028);
												mem_vec_5028 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5029);
												mem_vec_5029 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5030);
												mem_vec_5030 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5031);
												mem_vec_5031 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5032);
												mem_vec_5032 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5033);
												mem_vec_5033 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5034);
												mem_vec_5034 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5035);
												mem_vec_5035 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5036);
												mem_vec_5036 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5037);
												mem_vec_5037 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5038);
												mem_vec_5038 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5039);
												mem_vec_5039 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5040);
												mem_vec_5040 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5041);
												mem_vec_5041 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5020);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5021);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5022);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5023);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5024);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5025);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5026);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5027);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5028);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5029);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5030);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5031);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5032);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5033);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5034);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5035);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5036);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5037);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5038);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5039);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5040);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5041);
								}
							}
						}
					}
				}
				for (y = y340 + 11, yp_0 = 0;
					y < y340 + 11 + 45;
					y += 15, yp_0 += 15){
					// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
					// T (x, 1) (1 / 1)
					for (x648 = x649, x648_p_1 = x649_p_0, x648_p_0 = 0;
						x648 < x649 + 1;
						x648 += 1, x648_p_1 += 1, x648_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
						// T (h, 3) (3 / 1)
						for (h = h292, hp_0 = 0;
							h < h292 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w310, wp_0 = 0;
								w < w310 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
								// T (x, 1) (1 / 1)
								for (x = x648, xp_2 = x648_p_1, xp_1 = x648_p_0, xp_0 = 0;
									x < x648 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5042 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5043 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_5058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_5060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_5061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_5062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_5063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_5064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_5065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_5066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_5067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_5068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_5069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_5070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_5071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c510, cp_1 = c510_p_0, cp_0 = 0;
												c < c510 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5042);
												mem_vec_5042 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5043);
												mem_vec_5043 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5044);
												mem_vec_5044 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5045);
												mem_vec_5045 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5046);
												mem_vec_5046 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5047);
												mem_vec_5047 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5048);
												mem_vec_5048 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5049);
												mem_vec_5049 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5050);
												mem_vec_5050 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5051);
												mem_vec_5051 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5052);
												mem_vec_5052 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5053);
												mem_vec_5053 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5054);
												mem_vec_5054 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5055);
												mem_vec_5055 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5056);
												mem_vec_5056 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5057);
												mem_vec_5057 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5058);
												mem_vec_5058 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5059);
												mem_vec_5059 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5060);
												mem_vec_5060 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5061);
												mem_vec_5061 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5062);
												mem_vec_5062 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5063);
												mem_vec_5063 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_5064);
												mem_vec_5064 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_5065);
												mem_vec_5065 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_5066);
												mem_vec_5066 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_5067);
												mem_vec_5067 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_5068);
												mem_vec_5068 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_5069);
												mem_vec_5069 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_5070);
												mem_vec_5070 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_5071);
												mem_vec_5071 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5042);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5043);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5044);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5045);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5046);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5047);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5048);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5049);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5050);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5051);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5052);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5053);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5054);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5055);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5056);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5057);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5058);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5059);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5060);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5061);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5062);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5063);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_5064);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_5065);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_5066);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_5067);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_5068);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_5069);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_5070);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_5071);
								}
							}
						}
					}
				}
		}
	}
}


}