#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (8, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, x);
  T (2, f); T (4, f)]
*/
IND_TYPE c, cp_0, c417_p_0, cp_1, c417, f, fp_0, f476_p_0, f477_p_0, fp_1, f476_p_1, fp_2, f476, f477, h, hp_0, w, wp_0, x, xp_0, x417_p_0, xp_1, x417, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y307 = 0;
IND_TYPE x418 = 0;
IND_TYPE h259 = 0;
IND_TYPE w150 = 0;
IND_TYPE c418 = 0;
IND_TYPE f478 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_5060 ,mem_vec_5061 ,mem_vec_5062 ,mem_vec_5063 ,mem_vec_5064 ,mem_vec_5065 ,mem_vec_5066 ,mem_vec_5067 ,mem_vec_5068 ,mem_vec_5069 ,mem_vec_5070 ,mem_vec_5071 ,mem_vec_5072 ,mem_vec_5073 ,mem_vec_5074 ,mem_vec_5075 ,mem_vec_5076 ,mem_vec_5077 ,mem_vec_5078 ,mem_vec_5079 ,mem_vec_5080 ,mem_vec_5081 ,mem_vec_5082 ,mem_vec_5083 ,mem_vec_5084 ,mem_vec_5085 ,mem_vec_5086 ,mem_vec_5087 ,mem_vec_5088 ,mem_vec_5089 ,mem_vec_5090 ,mem_vec_5091 ,mem_vec_5092 ,mem_vec_5093 ,mem_vec_5094 ,mem_vec_5095 ,mem_vec_5096 ,mem_vec_5097 ,mem_vec_5098 ,mem_vec_5099 ,mem_vec_5100 ,mem_vec_5101 ,mem_vec_5102 ,mem_vec_5103 ,mem_vec_5104 ,mem_vec_5105 ,mem_vec_5106 ,mem_vec_5107 ,mem_vec_5108 ,mem_vec_5109 ,mem_vec_5110 ,mem_vec_5111 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f477 = f478, f477_p_0 = 0;
	f477 < f478 + 512;
	f477 += 128, f477_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (f, 2) (128 / 64)
	for (f476 = f477, f476_p_1 = f477_p_0, f476_p_0 = 0;
		f476 < f477 + 128;
		f476 += 64, f476_p_1 += 64, f476_p_0 += 64){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
		// T (x, 2) (34 / 17)
		for (x417 = x418, x417_p_0 = 0;
			x417 < x418 + 34;
			x417 += 17, x417_p_0 += 17){
				for (y = y307, yp_0 = 0;
					y < y307 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
					// T (f, 1) (64 / 64)
					for (f = f476, fp_2 = f476_p_1, fp_1 = f476_p_0, fp_0 = 0;
						f < f476 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 8) (256 / 32)
						for (c417 = c418, c417_p_0 = 0;
							c417 < c418 + 256;
							c417 += 32, c417_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
							// T (w, 3) (3 / 1)
							for (w = w150, wp_0 = 0;
								w < w150 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 64
								// T (x, 17) (17 / 1)
								for (x = x417, xp_1 = x417_p_0, xp_0 = 0;
									x < x417 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
									// T (h, 3) (3 / 1)
									for (h = h259, hp_0 = 0;
										h < h259 + 3;
										h += 1, hp_0 += 1){
												mem_vec_5060 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5061 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5062 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_5063 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_5064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_5067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_5068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_5071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_5072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_5075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_5076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_5079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_5080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_5083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
												// T (c, 32) (32 / 1)
												for (c = c417, cp_1 = c417_p_0, cp_0 = 0;
													c < c417 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5060);
													mem_vec_5060 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5061);
													mem_vec_5061 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5062);
													mem_vec_5062 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5063);
													mem_vec_5063 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5064);
													mem_vec_5064 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5065);
													mem_vec_5065 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5066);
													mem_vec_5066 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5067);
													mem_vec_5067 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5068);
													mem_vec_5068 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5069);
													mem_vec_5069 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5070);
													mem_vec_5070 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5071);
													mem_vec_5071 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5072);
													mem_vec_5072 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5073);
													mem_vec_5073 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5074);
													mem_vec_5074 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5075);
													mem_vec_5075 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5076);
													mem_vec_5076 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5077);
													mem_vec_5077 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5078);
													mem_vec_5078 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5079);
													mem_vec_5079 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5080);
													mem_vec_5080 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5081);
													mem_vec_5081 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5082);
													mem_vec_5082 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5083);
													mem_vec_5083 = vec_33;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5060);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5061);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5062);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5063);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5064);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5065);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5066);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5067);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5068);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5069);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5070);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5071);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5072);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5073);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5074);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5075);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5076);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5077);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5078);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5079);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5080);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5081);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5082);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5083);
									}
								}
							}
						}
					}
				}
				for (y = y307 + 6, yp_0 = 0;
					y < y307 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
					// T (f, 1) (64 / 64)
					for (f = f476, fp_2 = f476_p_1, fp_1 = f476_p_0, fp_0 = 0;
						f < f476 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 8) (256 / 32)
						for (c417 = c418, c417_p_0 = 0;
							c417 < c418 + 256;
							c417 += 32, c417_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
							// T (w, 3) (3 / 1)
							for (w = w150, wp_0 = 0;
								w < w150 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 64
								// T (x, 17) (17 / 1)
								for (x = x417, xp_1 = x417_p_0, xp_0 = 0;
									x < x417 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
									// T (h, 3) (3 / 1)
									for (h = h259, hp_0 = 0;
										h < h259 + 3;
										h += 1, hp_0 += 1){
												mem_vec_5084 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5085 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5086 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_5087 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_5088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_5091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_5092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_5095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_5096 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5097 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_5099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_5100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_5103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_5104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_5107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												mem_vec_5108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_5109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_5110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
												mem_vec_5111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
												// T (c, 32) (32 / 1)
												for (c = c417, cp_1 = c417_p_0, cp_0 = 0;
													c < c417 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5084);
													mem_vec_5084 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5085);
													mem_vec_5085 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5086);
													mem_vec_5086 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5087);
													mem_vec_5087 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5088);
													mem_vec_5088 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5089);
													mem_vec_5089 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5090);
													mem_vec_5090 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5091);
													mem_vec_5091 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5092);
													mem_vec_5092 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5093);
													mem_vec_5093 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5094);
													mem_vec_5094 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5095);
													mem_vec_5095 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5096);
													mem_vec_5096 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5097);
													mem_vec_5097 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5098);
													mem_vec_5098 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5099);
													mem_vec_5099 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5100);
													mem_vec_5100 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5101);
													mem_vec_5101 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5102);
													mem_vec_5102 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5103);
													mem_vec_5103 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5104);
													mem_vec_5104 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5105);
													mem_vec_5105 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5106);
													mem_vec_5106 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5107);
													mem_vec_5107 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_5108);
													mem_vec_5108 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_5109);
													mem_vec_5109 = vec_36;



													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_5110);
													mem_vec_5110 = vec_37;



													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_5111);
													mem_vec_5111 = vec_38;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5084);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5085);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5086);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5087);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5088);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5089);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5090);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5091);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5092);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5093);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5094);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5095);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5096);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5097);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5098);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5099);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5100);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5101);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5102);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5103);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5104);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5105);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5106);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5107);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5108);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5109);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_5110);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_5111);
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