#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (1, x); T (2, x);
  Lambda_apply y [((Iter 6), (Arg 9)); ((Iter 1), (Arg 14))]; T (4, f);
  T (16, c); T (34, x)]
*/
IND_TYPE c, cp_0, c864_p_0, cp_1, c864, f, fp_0, x, xp_0, x1152_p_0, x1153_p_0, xp_1, x1152_p_1, xp_2, x1152, x1153, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y576 = 0;
IND_TYPE x1154 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c865 = 0;
IND_TYPE f576 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10700 ,mem_vec_10701 ,mem_vec_10702 ,mem_vec_10703 ,mem_vec_10704 ,mem_vec_10705 ,mem_vec_10706 ,mem_vec_10707 ,mem_vec_10708 ,mem_vec_10709 ,mem_vec_10710 ,mem_vec_10711 ,mem_vec_10712 ,mem_vec_10713 ,mem_vec_10714 ,mem_vec_10715 ,mem_vec_10716 ,mem_vec_10717 ,mem_vec_10718 ,mem_vec_10719 ,mem_vec_10720 ,mem_vec_10721 ,mem_vec_10722 ,mem_vec_10723 ,mem_vec_10724 ,mem_vec_10725 ,mem_vec_10726 ,mem_vec_10727 ,mem_vec_10728 ,mem_vec_10729 ,mem_vec_10730 ,mem_vec_10731 ,mem_vec_10732 ,mem_vec_10733 ,mem_vec_10734 ,mem_vec_10735 ,mem_vec_10736 ,mem_vec_10737 ,mem_vec_10738 ,mem_vec_10739 ,mem_vec_10740 ,mem_vec_10741 ,mem_vec_10742 ,mem_vec_10743 ,mem_vec_10744 ,mem_vec_10745 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 34) (68 / 2)
for (x1153 = x1154, x1153_p_0 = 0;
	x1153 < x1154 + 68;
	x1153 += 2, x1153_p_0 += 2){
	// y = 68, x = 2, h = 1, w = 1, c = 256, f = 128
	// T (c, 16) (256 / 16)
	for (c864 = c865, c864_p_0 = 0;
		c864 < c865 + 256;
		c864 += 16, c864_p_0 += 16){
		// y = 68, x = 2, h = 1, w = 1, c = 16, f = 128
		// T (f, 4) (128 / 32)
		for (f = f576, fp_0 = 0;
			f < f576 + 128;
			f += 32, fp_0 += 32){
				for (y = y576, yp_0 = 0;
					y < y576 + 54;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 2, h = 1, w = 1, c = 16, f = 32
					// T (x, 2) (2 / 1)
					for (x1152 = x1153, x1152_p_1 = x1153_p_0, x1152_p_0 = 0;
						x1152 < x1153 + 2;
						x1152 += 1, x1152_p_1 += 1, x1152_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1152, xp_2 = x1152_p_1, xp_1 = x1152_p_0, xp_0 = 0;
							x < x1152 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10700 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10701 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_10715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_10716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_10717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c864, cp_1 = c864_p_0, cp_0 = 0;
										c < c864 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10700);
										mem_vec_10700 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10701);
										mem_vec_10701 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10702);
										mem_vec_10702 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10703);
										mem_vec_10703 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10704);
										mem_vec_10704 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10705);
										mem_vec_10705 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10706);
										mem_vec_10706 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10707);
										mem_vec_10707 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10708);
										mem_vec_10708 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10709);
										mem_vec_10709 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10710);
										mem_vec_10710 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10711);
										mem_vec_10711 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10712);
										mem_vec_10712 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10713);
										mem_vec_10713 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10714);
										mem_vec_10714 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10715);
										mem_vec_10715 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10716);
										mem_vec_10716 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10717);
										mem_vec_10717 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10700);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10701);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10702);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10703);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10704);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10705);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10706);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10707);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10708);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10709);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10710);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10711);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10712);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10713);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10714);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10715);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10716);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10717);
						}
					}
				}
				for (y = y576 + 54, yp_0 = 0;
					y < y576 + 54 + 14;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 2, h = 1, w = 1, c = 16, f = 32
					// T (x, 2) (2 / 1)
					for (x1152 = x1153, x1152_p_1 = x1153_p_0, x1152_p_0 = 0;
						x1152 < x1153 + 2;
						x1152 += 1, x1152_p_1 += 1, x1152_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1152, xp_2 = x1152_p_1, xp_1 = x1152_p_0, xp_0 = 0;
							x < x1152 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10718 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10719 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_10733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_10734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_10735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_10736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_10737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_10738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_10739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_10740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_10741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_10742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_10743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_10744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_10745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c864, cp_1 = c864_p_0, cp_0 = 0;
										c < c864 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10718);
										mem_vec_10718 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10719);
										mem_vec_10719 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10720);
										mem_vec_10720 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10721);
										mem_vec_10721 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10722);
										mem_vec_10722 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10723);
										mem_vec_10723 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10724);
										mem_vec_10724 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10725);
										mem_vec_10725 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10726);
										mem_vec_10726 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10727);
										mem_vec_10727 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10728);
										mem_vec_10728 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10729);
										mem_vec_10729 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10730);
										mem_vec_10730 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10731);
										mem_vec_10731 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10732);
										mem_vec_10732 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10733);
										mem_vec_10733 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10734);
										mem_vec_10734 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10735);
										mem_vec_10735 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10736);
										mem_vec_10736 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10737);
										mem_vec_10737 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10738);
										mem_vec_10738 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10739);
										mem_vec_10739 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10740);
										mem_vec_10740 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10741);
										mem_vec_10741 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_10742);
										mem_vec_10742 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_10743);
										mem_vec_10743 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_10744);
										mem_vec_10744 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_10745);
										mem_vec_10745 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10718);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10719);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10720);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10721);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10722);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10723);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10724);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10725);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10726);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10727);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10728);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10729);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10730);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10731);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10732);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10733);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10734);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10735);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10736);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10737);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10738);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10739);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10740);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10741);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_10742);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_10743);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_10744);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_10745);
						}
					}
				}
		}
	}
}


}