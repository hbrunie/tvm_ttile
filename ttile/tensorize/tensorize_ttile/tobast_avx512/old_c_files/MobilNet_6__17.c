#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (7, x);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 1), (Arg 8))];
  T (4, f); T (2, c); T (2, f); T (128, c); T (2, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1242_p_0, c1243_p_0, cp_1, c1242_p_1, cp_2, c1242, c1243, f, fp_0, f1218_p_0, f1219_p_0, fp_1, f1218_p_1, fp_2, f1218, f1219, h, hp_0, x, xp_0, x994_p_0, xp_1, x994, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y664 = 0;
IND_TYPE x995 = 0;
IND_TYPE h606 = 0;
IND_TYPE w = 0;
IND_TYPE c1244 = 0;
IND_TYPE f1220 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7068 ,mem_vec_7069 ,mem_vec_7070 ,mem_vec_7071 ,mem_vec_7072 ,mem_vec_7073 ,mem_vec_7074 ,mem_vec_7075 ,mem_vec_7076 ,mem_vec_7077 ,mem_vec_7078 ,mem_vec_7079 ,mem_vec_7080 ,mem_vec_7081 ,mem_vec_7082 ,mem_vec_7083 ,mem_vec_7084 ,mem_vec_7085 ,mem_vec_7086 ,mem_vec_7087 ,mem_vec_7088 ,mem_vec_7089 ,mem_vec_7090 ,mem_vec_7091 ,mem_vec_7092 ,mem_vec_7093 ,mem_vec_7094 ,mem_vec_7095 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f1219 = f1220, f1219_p_0 = 0;
	f1219 < f1220 + 256;
	f1219 += 256, f1219_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
	// T (x, 2) (14 / 7)
	for (x994 = x995, x994_p_0 = 0;
		x994 < x995 + 14;
		x994 += 7, x994_p_0 += 7){
		// y = 14, x = 7, h = 3, w = 3, c = 256, f = 256
		// T (c, 128) (256 / 2)
		for (c1243 = c1244, c1243_p_0 = 0;
			c1243 < c1244 + 256;
			c1243 += 2, c1243_p_0 += 2){
			// y = 14, x = 7, h = 3, w = 3, c = 2, f = 256
			// T (f, 2) (256 / 128)
			for (f1218 = f1219, f1218_p_1 = f1219_p_0, f1218_p_0 = 0;
				f1218 < f1219 + 256;
				f1218 += 128, f1218_p_1 += 128, f1218_p_0 += 128){
				// y = 14, x = 7, h = 3, w = 3, c = 2, f = 128
				// T (c, 2) (2 / 1)
				for (c1242 = c1243, c1242_p_1 = c1243_p_0, c1242_p_0 = 0;
					c1242 < c1243 + 2;
					c1242 += 1, c1242_p_1 += 1, c1242_p_0 += 1){
					// y = 14, x = 7, h = 3, w = 3, c = 1, f = 128
					// T (f, 4) (128 / 32)
					for (f = f1218, fp_2 = f1218_p_1, fp_1 = f1218_p_0, fp_0 = 0;
						f < f1218 + 128;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y664, yp_0 = 0;
								y < y664 + 6;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 32
								// T (h, 3) (3 / 1)
								for (h = h606, hp_0 = 0;
									h < h606 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 32
									// T (x, 7) (7 / 1)
									for (x = x994, xp_1 = x994_p_0, xp_0 = 0;
										x < x994 + 7;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7068 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_7069 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_7070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_7071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_7072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_7073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_7074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_7075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_7076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_7077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_7078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_7079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c1242, cp_2 = c1242_p_1, cp_1 = c1242_p_0, cp_0 = 0;
													c < c1242 + 1;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7068);
													mem_vec_7068 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7069);
													mem_vec_7069 = vec_3;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7070);
													mem_vec_7070 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7071);
													mem_vec_7071 = vec_7;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7072);
													mem_vec_7072 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7073);
													mem_vec_7073 = vec_10;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7074);
													mem_vec_7074 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7075);
													mem_vec_7075 = vec_13;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7076);
													mem_vec_7076 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7077);
													mem_vec_7077 = vec_16;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7078);
													mem_vec_7078 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7079);
													mem_vec_7079 = vec_19;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_7068);
													mem_vec_7068 = vec_20;

													vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_7069);
													mem_vec_7069 = vec_23;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_7070);
													mem_vec_7070 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_7071);
													mem_vec_7071 = vec_27;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);


													vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_7072);
													mem_vec_7072 = vec_28;



													vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_7073);
													mem_vec_7073 = vec_30;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);


													vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_7074);
													mem_vec_7074 = vec_31;



													vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_7075);
													mem_vec_7075 = vec_33;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_7076);
													mem_vec_7076 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_7077);
													mem_vec_7077 = vec_36;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
													vec_38 = _mm512_set1_ps(scal_11);


													vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_7078);
													mem_vec_7078 = vec_37;



													vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_7079);
													mem_vec_7079 = vec_39;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_41 = _mm512_set1_ps(scal_12);
													vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_7068);
													mem_vec_7068 = vec_40;

													vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_7069);
													mem_vec_7069 = vec_43;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_46 = _mm512_set1_ps(scal_13);


													vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_7070);
													mem_vec_7070 = vec_45;



													vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_7071);
													mem_vec_7071 = vec_47;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_49 = _mm512_set1_ps(scal_14);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_7072);
													mem_vec_7072 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_7073);
													mem_vec_7073 = vec_50;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_52 = _mm512_set1_ps(scal_15);


													vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_7074);
													mem_vec_7074 = vec_51;



													vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_7075);
													mem_vec_7075 = vec_53;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
													vec_55 = _mm512_set1_ps(scal_16);


													vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_7076);
													mem_vec_7076 = vec_54;



													vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_7077);
													mem_vec_7077 = vec_56;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
													vec_58 = _mm512_set1_ps(scal_17);


													vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_7078);
													mem_vec_7078 = vec_57;



													vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_7079);
													mem_vec_7079 = vec_59;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7068);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7069);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7070);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7071);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7072);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7073);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7074);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7075);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7076);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7077);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7078);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7079);
									}
								}
							}
							for (y = y664 + 6, yp_0 = 0;
								y < y664 + 6 + 8;
								y += 8, yp_0 += 8){
								// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 32
								// T (h, 3) (3 / 1)
								for (h = h606, hp_0 = 0;
									h < h606 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 32
									// T (x, 7) (7 / 1)
									for (x = x994, xp_1 = x994_p_0, xp_0 = 0;
										x < x994 + 7;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7080 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_7081 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_7082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_7083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_7084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_7085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_7086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_7087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_7088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_7089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_7090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_7091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_7092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_7093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_7094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_7095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c1242, cp_2 = c1242_p_1, cp_1 = c1242_p_0, cp_0 = 0;
													c < c1242 + 1;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7080);
													mem_vec_7080 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7081);
													mem_vec_7081 = vec_3;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7082);
													mem_vec_7082 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7083);
													mem_vec_7083 = vec_7;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7084);
													mem_vec_7084 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7085);
													mem_vec_7085 = vec_10;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7086);
													mem_vec_7086 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7087);
													mem_vec_7087 = vec_13;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7088);
													mem_vec_7088 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7089);
													mem_vec_7089 = vec_16;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7090);
													mem_vec_7090 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7091);
													mem_vec_7091 = vec_19;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7092);
													mem_vec_7092 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7093);
													mem_vec_7093 = vec_22;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7094);
													mem_vec_7094 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7095);
													mem_vec_7095 = vec_25;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_7080);
													mem_vec_7080 = vec_26;

													vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_7081);
													mem_vec_7081 = vec_29;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);


													vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_7082);
													mem_vec_7082 = vec_31;



													vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_7083);
													mem_vec_7083 = vec_33;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_7084);
													mem_vec_7084 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_7085);
													mem_vec_7085 = vec_36;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_38 = _mm512_set1_ps(scal_11);


													vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_7086);
													mem_vec_7086 = vec_37;



													vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_7087);
													mem_vec_7087 = vec_39;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
													vec_41 = _mm512_set1_ps(scal_12);


													vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_7088);
													mem_vec_7088 = vec_40;



													vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_7089);
													mem_vec_7089 = vec_42;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
													vec_44 = _mm512_set1_ps(scal_13);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7090);
													mem_vec_7090 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7091);
													mem_vec_7091 = vec_45;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
													vec_47 = _mm512_set1_ps(scal_14);


													vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_7092);
													mem_vec_7092 = vec_46;



													vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_7093);
													mem_vec_7093 = vec_48;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 7) + h) + c];
													vec_50 = _mm512_set1_ps(scal_15);


													vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_7094);
													mem_vec_7094 = vec_49;



													vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_7095);
													mem_vec_7095 = vec_51;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_53 = _mm512_set1_ps(scal_16);
													vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_7080);
													mem_vec_7080 = vec_52;

													vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_7081);
													mem_vec_7081 = vec_55;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_58 = _mm512_set1_ps(scal_17);


													vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_7082);
													mem_vec_7082 = vec_57;



													vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_7083);
													mem_vec_7083 = vec_59;
													scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_61 = _mm512_set1_ps(scal_18);


													vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_7084);
													mem_vec_7084 = vec_60;



													vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_7085);
													mem_vec_7085 = vec_62;
													scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_64 = _mm512_set1_ps(scal_19);


													vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_7086);
													mem_vec_7086 = vec_63;



													vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_7087);
													mem_vec_7087 = vec_65;
													scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
													vec_67 = _mm512_set1_ps(scal_20);


													vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_7088);
													mem_vec_7088 = vec_66;



													vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_7089);
													mem_vec_7089 = vec_68;
													scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
													vec_70 = _mm512_set1_ps(scal_21);


													vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_7090);
													mem_vec_7090 = vec_69;



													vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_7091);
													mem_vec_7091 = vec_71;
													scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
													vec_73 = _mm512_set1_ps(scal_22);


													vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_7092);
													mem_vec_7092 = vec_72;



													vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_7093);
													mem_vec_7093 = vec_74;
													scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 7) + h) + c];
													vec_76 = _mm512_set1_ps(scal_23);


													vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_7094);
													mem_vec_7094 = vec_75;



													vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_7095);
													mem_vec_7095 = vec_77;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7080);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7081);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7082);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7083);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7084);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7085);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7086);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7087);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7088);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7089);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7090);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7091);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7092);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7093);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7094);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7095);
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