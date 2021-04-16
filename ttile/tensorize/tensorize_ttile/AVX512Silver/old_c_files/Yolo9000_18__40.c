#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (3, h);
  T (17, x); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (2, f);
  T (32, c); T (16, f)]
*/
IND_TYPE c, cp_0, c164_p_0, c165_p_0, cp_1, c164_p_1, cp_2, c164, c165, f, fp_0, f123_p_0, fp_1, f123, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y82 = 0;
IND_TYPE x82 = 0;
IND_TYPE h62 = 0;
IND_TYPE w = 0;
IND_TYPE c166 = 0;
IND_TYPE f124 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,mem_vec_972 ,mem_vec_973 ,mem_vec_974 ,mem_vec_975 ,mem_vec_976 ,mem_vec_977 ,mem_vec_978 ,mem_vec_979 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
for (f123 = f124, f123_p_0 = 0;
	f123 < f124 + 1024;
	f123 += 64, f123_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
	// T (c, 32) (512 / 16)
	for (c165 = c166, c165_p_0 = 0;
		c165 < c166 + 512;
		c165 += 16, c165_p_0 += 16){
		// y = 17, x = 17, h = 3, w = 3, c = 16, f = 64
		// T (f, 2) (64 / 32)
		for (f = f123, fp_1 = f123_p_0, fp_0 = 0;
			f < f123 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y82, yp_0 = 0;
					y < y82 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
					// T (c, 1) (16 / 16)
					for (c164 = c165, c164_p_1 = c165_p_0, c164_p_0 = 0;
						c164 < c165 + 16;
						c164 += 16, c164_p_1 += 16, c164_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x82, xp_0 = 0;
							x < x82 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h62, hp_0 = 0;
								h < h62 + 3;
								h += 1, hp_0 += 1){
										mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_959 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c164, cp_2 = c164_p_1, cp_1 = c164_p_0, cp_0 = 0;
											c < c164 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_958);
											mem_vec_958 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_959);
											mem_vec_959 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_960);
											mem_vec_960 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_961);
											mem_vec_961 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_962);
											mem_vec_962 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_963);
											mem_vec_963 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_964);
											mem_vec_964 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_965);
											mem_vec_965 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_966);
											mem_vec_966 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_967);
											mem_vec_967 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_19 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_958);
											mem_vec_958 = vec_17;

											vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_20 = _mm512_fmadd_ps(vec_18, vec_21, mem_vec_959);
											mem_vec_959 = vec_20;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_23 = _mm512_set1_ps(scal_6);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_960);
											mem_vec_960 = vec_22;



											vec_24 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_961);
											mem_vec_961 = vec_24;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_26 = _mm512_set1_ps(scal_7);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_19, mem_vec_962);
											mem_vec_962 = vec_25;



											vec_27 = _mm512_fmadd_ps(vec_26, vec_21, mem_vec_963);
											mem_vec_963 = vec_27;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_964);
											mem_vec_964 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_965);
											mem_vec_965 = vec_30;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_19, mem_vec_966);
											mem_vec_966 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_21, mem_vec_967);
											mem_vec_967 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_958);
											mem_vec_958 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_959);
											mem_vec_959 = vec_37;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_40 = _mm512_set1_ps(scal_11);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_960);
											mem_vec_960 = vec_39;



											vec_41 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_961);
											mem_vec_961 = vec_41;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_43 = _mm512_set1_ps(scal_12);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_36, mem_vec_962);
											mem_vec_962 = vec_42;



											vec_44 = _mm512_fmadd_ps(vec_43, vec_38, mem_vec_963);
											mem_vec_963 = vec_44;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_46 = _mm512_set1_ps(scal_13);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_964);
											mem_vec_964 = vec_45;



											vec_47 = _mm512_fmadd_ps(vec_46, vec_38, mem_vec_965);
											mem_vec_965 = vec_47;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_49 = _mm512_set1_ps(scal_14);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_966);
											mem_vec_966 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_967);
											mem_vec_967 = vec_50;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_958);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_959);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_960);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_961);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_962);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_963);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_964);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_965);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_966);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_967);
							}
						}
					}
				}
				for (y = y82 + 5, yp_0 = 0;
					y < y82 + 5 + 12;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
					// T (c, 1) (16 / 16)
					for (c164 = c165, c164_p_1 = c165_p_0, c164_p_0 = 0;
						c164 < c165 + 16;
						c164 += 16, c164_p_1 += 16, c164_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x82, xp_0 = 0;
							x < x82 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h62, hp_0 = 0;
								h < h62 + 3;
								h += 1, hp_0 += 1){
										mem_vec_968 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_969 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c164, cp_2 = c164_p_1, cp_1 = c164_p_0, cp_0 = 0;
											c < c164 + 16;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_968);
											mem_vec_968 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_969);
											mem_vec_969 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_970);
											mem_vec_970 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_971);
											mem_vec_971 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_972);
											mem_vec_972 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_973);
											mem_vec_973 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_974);
											mem_vec_974 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_975);
											mem_vec_975 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_976);
											mem_vec_976 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_977);
											mem_vec_977 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_978);
											mem_vec_978 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_979);
											mem_vec_979 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_968);
											mem_vec_968 = vec_20;

											vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_969);
											mem_vec_969 = vec_23;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_26 = _mm512_set1_ps(scal_7);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_970);
											mem_vec_970 = vec_25;



											vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_971);
											mem_vec_971 = vec_27;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_972);
											mem_vec_972 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_973);
											mem_vec_973 = vec_30;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_974);
											mem_vec_974 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_975);
											mem_vec_975 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_976);
											mem_vec_976 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_977);
											mem_vec_977 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_978);
											mem_vec_978 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_979);
											mem_vec_979 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);
											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_968);
											mem_vec_968 = vec_40;

											vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_969);
											mem_vec_969 = vec_43;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_46 = _mm512_set1_ps(scal_13);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_970);
											mem_vec_970 = vec_45;



											vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_971);
											mem_vec_971 = vec_47;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_14);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_972);
											mem_vec_972 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_973);
											mem_vec_973 = vec_50;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_52 = _mm512_set1_ps(scal_15);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_974);
											mem_vec_974 = vec_51;



											vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_975);
											mem_vec_975 = vec_53;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_55 = _mm512_set1_ps(scal_16);


											vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_976);
											mem_vec_976 = vec_54;



											vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_977);
											mem_vec_977 = vec_56;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_978);
											mem_vec_978 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_979);
											mem_vec_979 = vec_59;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_968);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_969);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_970);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_971);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_972);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_973);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_974);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_975);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_976);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_977);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_978);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_979);
							}
						}
					}
				}
		}
	}
}


}