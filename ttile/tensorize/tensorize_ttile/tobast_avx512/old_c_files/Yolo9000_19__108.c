#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (16, c);
  T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (4, c)]
*/
IND_TYPE c, cp_0, c1264_p_0, c1265_p_0, cp_1, c1264_p_1, cp_2, c1264, c1265, f, fp_0, x, xp_0, x948_p_0, xp_1, x948, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y632 = 0;
IND_TYPE x949 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1266 = 0;
IND_TYPE f632 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_10728 ,mem_vec_10729 ,mem_vec_10730 ,mem_vec_10731 ,mem_vec_10732 ,mem_vec_10733 ,mem_vec_10734 ,mem_vec_10735 ,mem_vec_10736 ,mem_vec_10737 ,mem_vec_10738 ,mem_vec_10739 ,mem_vec_10740 ,mem_vec_10741 ,mem_vec_10742 ,mem_vec_10743 ,mem_vec_10744 ,mem_vec_10745 ,mem_vec_10746 ,mem_vec_10747 ,mem_vec_10748 ,mem_vec_10749 ,mem_vec_10750 ,mem_vec_10751 ,mem_vec_10752 ,mem_vec_10753 ,mem_vec_10754 ,mem_vec_10755 ,mem_vec_10756 ,mem_vec_10757 ,mem_vec_10758 ,mem_vec_10759 ,mem_vec_10760 ,mem_vec_10761 ,mem_vec_10762 ,mem_vec_10763 ,mem_vec_10764 ,mem_vec_10765 ,mem_vec_10766 ,mem_vec_10767 ,mem_vec_10768 ,mem_vec_10769 ,mem_vec_10770 ,mem_vec_10771 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 4) (1024 / 256)
for (c1265 = c1266, c1265_p_0 = 0;
	c1265 < c1266 + 1024;
	c1265 += 256, c1265_p_0 += 256){
		for (y = y632, yp_0 = 0;
			y < y632 + 5;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
			// T (x, 1) (17 / 17)
			for (x948 = x949, x948_p_0 = 0;
				x948 < x949 + 17;
				x948 += 17, x948_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
				// T (f, 8) (512 / 64)
				for (f = f632, fp_0 = 0;
					f < f632 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 16) (256 / 16)
					for (c1264 = c1265, c1264_p_1 = c1265_p_0, c1264_p_0 = 0;
						c1264 < c1265 + 256;
						c1264 += 16, c1264_p_1 += 16, c1264_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x948, xp_1 = x948_p_0, xp_0 = 0;
							x < x948 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10728 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10729 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10730 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10731 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1264, cp_2 = c1264_p_1, cp_1 = c1264_p_0, cp_0 = 0;
										c < c1264 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10728);
										mem_vec_10728 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10729);
										mem_vec_10729 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10730);
										mem_vec_10730 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10731);
										mem_vec_10731 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10732);
										mem_vec_10732 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10733);
										mem_vec_10733 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10734);
										mem_vec_10734 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10735);
										mem_vec_10735 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10736);
										mem_vec_10736 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10737);
										mem_vec_10737 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10738);
										mem_vec_10738 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10739);
										mem_vec_10739 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10740);
										mem_vec_10740 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10741);
										mem_vec_10741 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10742);
										mem_vec_10742 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10743);
										mem_vec_10743 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10744);
										mem_vec_10744 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10745);
										mem_vec_10745 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10746);
										mem_vec_10746 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10747);
										mem_vec_10747 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10728);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10729);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10730);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10731);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10732);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10733);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10734);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10735);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10736);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10737);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10738);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10739);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10740);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10741);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10742);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10743);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10744);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10745);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10746);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10747);
						}
					}
				}
			}
		}
		for (y = y632 + 5, yp_0 = 0;
			y < y632 + 5 + 12;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
			// T (x, 1) (17 / 17)
			for (x948 = x949, x948_p_0 = 0;
				x948 < x949 + 17;
				x948 += 17, x948_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
				// T (f, 8) (512 / 64)
				for (f = f632, fp_0 = 0;
					f < f632 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 16) (256 / 16)
					for (c1264 = c1265, c1264_p_1 = c1265_p_0, c1264_p_0 = 0;
						c1264 < c1265 + 256;
						c1264 += 16, c1264_p_1 += 16, c1264_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x948, xp_1 = x948_p_0, xp_0 = 0;
							x < x948 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10748 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10749 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10750 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10751 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_10768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_10771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1264, cp_2 = c1264_p_1, cp_1 = c1264_p_0, cp_0 = 0;
										c < c1264 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10748);
										mem_vec_10748 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10749);
										mem_vec_10749 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10750);
										mem_vec_10750 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10751);
										mem_vec_10751 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10752);
										mem_vec_10752 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10753);
										mem_vec_10753 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10754);
										mem_vec_10754 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10755);
										mem_vec_10755 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10756);
										mem_vec_10756 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10757);
										mem_vec_10757 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10758);
										mem_vec_10758 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10759);
										mem_vec_10759 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10760);
										mem_vec_10760 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10761);
										mem_vec_10761 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10762);
										mem_vec_10762 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10763);
										mem_vec_10763 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10764);
										mem_vec_10764 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10765);
										mem_vec_10765 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10766);
										mem_vec_10766 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10767);
										mem_vec_10767 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10768);
										mem_vec_10768 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10769);
										mem_vec_10769 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_10770);
										mem_vec_10770 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_10771);
										mem_vec_10771 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10748);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10749);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10750);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10751);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10752);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10753);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10754);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10755);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10756);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10757);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10758);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10759);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10760);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10761);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10762);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10763);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10764);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10765);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10766);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10767);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10768);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10769);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_10770);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_10771);
						}
					}
				}
			}
		}
}


}