#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (3, w);
  T (17, x); T (2, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (2, f);
  T (32, c); T (16, f)]
*/
IND_TYPE c, cp_0, c100_p_0, c101_p_0, cp_1, c100_p_1, cp_2, c100, c101, f, fp_0, f75_p_0, fp_1, f75, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y50 = 0;
IND_TYPE x50 = 0;
IND_TYPE h = 0;
IND_TYPE w50 = 0;
IND_TYPE c102 = 0;
IND_TYPE f76 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
for (f75 = f76, f75_p_0 = 0;
	f75 < f76 + 1024;
	f75 += 64, f75_p_0 += 64){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
	// T (c, 32) (512 / 16)
	for (c101 = c102, c101_p_0 = 0;
		c101 < c102 + 512;
		c101 += 16, c101_p_0 += 16){
		// y = 17, x = 17, h = 3, w = 3, c = 16, f = 64
		// T (f, 2) (64 / 32)
		for (f = f75, fp_1 = f75_p_0, fp_0 = 0;
			f < f75 + 64;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y50, yp_0 = 0;
					y < y50 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
					// T (c, 2) (16 / 8)
					for (c100 = c101, c100_p_1 = c101_p_0, c100_p_0 = 0;
						c100 < c101 + 16;
						c100 += 8, c100_p_1 += 8, c100_p_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x50, xp_0 = 0;
							x < x50 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w50, wp_0 = 0;
								w < w50 + 3;
								w += 1, wp_0 += 1){
										mem_vec_680 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_681 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c100, cp_2 = c100_p_1, cp_1 = c100_p_0, cp_0 = 0;
											c < c100 + 8;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_680);
											mem_vec_680 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_681);
											mem_vec_681 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_682);
											mem_vec_682 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_683);
											mem_vec_683 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_684);
											mem_vec_684 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_685);
											mem_vec_685 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_686);
											mem_vec_686 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_687);
											mem_vec_687 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_688);
											mem_vec_688 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_689);
											mem_vec_689 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_690);
											mem_vec_690 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_691);
											mem_vec_691 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_692);
											mem_vec_692 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_693);
											mem_vec_693 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_694);
											mem_vec_694 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_695);
											mem_vec_695 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_680);
											mem_vec_680 = vec_26;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_681);
											mem_vec_681 = vec_29;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_682);
											mem_vec_682 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_683);
											mem_vec_683 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_684);
											mem_vec_684 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_685);
											mem_vec_685 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_686);
											mem_vec_686 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_687);
											mem_vec_687 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_688);
											mem_vec_688 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_689);
											mem_vec_689 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_690);
											mem_vec_690 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_691);
											mem_vec_691 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_692);
											mem_vec_692 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_693);
											mem_vec_693 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_694);
											mem_vec_694 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_695);
											mem_vec_695 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_53 = _mm512_set1_ps(scal_16);
											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_680);
											mem_vec_680 = vec_52;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_681);
											mem_vec_681 = vec_55;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_682);
											mem_vec_682 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_683);
											mem_vec_683 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_61 = _mm512_set1_ps(scal_18);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_684);
											mem_vec_684 = vec_60;



											vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_685);
											mem_vec_685 = vec_62;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_686);
											mem_vec_686 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_687);
											mem_vec_687 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_688);
											mem_vec_688 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_689);
											mem_vec_689 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_690);
											mem_vec_690 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_691);
											mem_vec_691 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_692);
											mem_vec_692 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_693);
											mem_vec_693 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_694);
											mem_vec_694 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_695);
											mem_vec_695 = vec_77;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_680);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_681);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_682);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_683);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_684);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_685);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_686);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_687);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_688);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_689);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_690);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_691);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_692);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_693);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_694);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_695);
							}
						}
					}
				}
				for (y = y50 + 8, yp_0 = 0;
					y < y50 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
					// T (c, 2) (16 / 8)
					for (c100 = c101, c100_p_1 = c101_p_0, c100_p_0 = 0;
						c100 < c101 + 16;
						c100 += 8, c100_p_1 += 8, c100_p_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 32
						// T (x, 17) (17 / 1)
						for (x = x50, xp_0 = 0;
							x < x50 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w50, wp_0 = 0;
								w < w50 + 3;
								w += 1, wp_0 += 1){
										mem_vec_696 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_697 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c100, cp_2 = c100_p_1, cp_1 = c100_p_0, cp_0 = 0;
											c < c100 + 8;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_696);
											mem_vec_696 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_697);
											mem_vec_697 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_698);
											mem_vec_698 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_699);
											mem_vec_699 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_700);
											mem_vec_700 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_701);
											mem_vec_701 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_702);
											mem_vec_702 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_703);
											mem_vec_703 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_704);
											mem_vec_704 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_705);
											mem_vec_705 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_706);
											mem_vec_706 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_707);
											mem_vec_707 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_708);
											mem_vec_708 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_709);
											mem_vec_709 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_710);
											mem_vec_710 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_711);
											mem_vec_711 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_712);
											mem_vec_712 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_713);
											mem_vec_713 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_696);
											mem_vec_696 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_697);
											mem_vec_697 = vec_32;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_698);
											mem_vec_698 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_699);
											mem_vec_699 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_700);
											mem_vec_700 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_701);
											mem_vec_701 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_702);
											mem_vec_702 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_703);
											mem_vec_703 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_704);
											mem_vec_704 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_705);
											mem_vec_705 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_706);
											mem_vec_706 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_707);
											mem_vec_707 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_708);
											mem_vec_708 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_709);
											mem_vec_709 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_710);
											mem_vec_710 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_711);
											mem_vec_711 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_712);
											mem_vec_712 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_713);
											mem_vec_713 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_696);
											mem_vec_696 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_697);
											mem_vec_697 = vec_61;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_698);
											mem_vec_698 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_699);
											mem_vec_699 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_700);
											mem_vec_700 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_701);
											mem_vec_701 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_702);
											mem_vec_702 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_703);
											mem_vec_703 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_704);
											mem_vec_704 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_705);
											mem_vec_705 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_706);
											mem_vec_706 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_707);
											mem_vec_707 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_708);
											mem_vec_708 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_709);
											mem_vec_709 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_710);
											mem_vec_710 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_711);
											mem_vec_711 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_712);
											mem_vec_712 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_713);
											mem_vec_713 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_696);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_697);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_698);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_699);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_700);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_701);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_702);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_703);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_704);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_705);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_706);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_707);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_708);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_709);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_710);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_711);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_712);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_713);
							}
						}
					}
				}
		}
	}
}


}