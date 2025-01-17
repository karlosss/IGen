#include "gaol_common.h"

f64i_gal cospi(f64i_gal x);
f64i_gal sinpi(f64i_gal x);
static f64i_gal D1[64];

void init_DFT32_gal() {
    for(int i3 = 0; i3 <= 3; i3++) {
        for(int i10 = 0; i10 <= 1; i10++) {
            for(int i14 = 0; i14 <= 1; i14++) {
                D1[((16*i3) + (8*i10) + (4*i14))] = cospi((((f64i_gal )(2*(i3*((2*i14) + i10)))) / 32));
                D1[(1 + (16*i3) + (8*i10) + (4*i14))] = sinpi((((f64i_gal )(2*(((2*(i3*((2*i14) + i10))) + 1) / 2))) / 32));
                D1[(2 + (16*i3) + (8*i10) + (4*i14))] = cospi((((f64i_gal )(2*(i3*(4 + (2*i14) + i10)))) / 32));
                D1[(3 + (16*i3) + (8*i10) + (4*i14))] = sinpi((((f64i_gal )(2*(((2*(i3*(4 + (2*i14) + i10))) + 1) / 2))) / 32));
            }
        }
    }
}

void DFT32(f64i_gal  *Y, f64i_gal  *X) {
    static f64i_gal T1[64];
    for(int i3 = 0; i3 <= 3; i3++) {
        int a301, a302, a303, a304, a305, a306, a307, a308
                , a311, a312, a313, a314, a315, a316, a317, a318
                , a321, a322, a323, a324, a325, a326, a327, a328
                , a329, a330, a331, a332, a333, a334, a335, a336;
        f64i_gal a309, a310, a319, a320, s61, s62, s63, s64
                , t181, t182, t183, t184, t185, t186, t187, t188
                , t189, t190, t191, t192, t193, t194, t195, t196
                , t197, t198, t199, t200, t201, t202, t203, t204
                , t205, t206, t207, t208, t209, t210, t211, t212
                , t213, t214, t215, t216, t217, t218, t219, t220
                , t221, t222, t223, t224;
        a301 = (2*i3);
        a302 = (a301 + 1);
        a303 = (a301 + 32);
        a304 = (a301 + 33);
        t181 = (*((X + a301)) + *((X + a303)));
        t182 = (*((X + a302)) + *((X + a304)));
        t183 = (*((X + a301)) - *((X + a303)));
        t184 = (*((X + a302)) - *((X + a304)));
        a305 = (a301 + 8);
        a306 = (a301 + 9);
        a307 = (a301 + 40);
        a308 = (a301 + 41);
        t185 = (*((X + a305)) + *((X + a307)));
        t186 = (*((X + a306)) + *((X + a308)));
        a309 = (0.70710678118654757*(*((X + a305)) - *((X + a307))));
        a310 = (0.70710678118654757*(*((X + a306)) - *((X + a308))));
        s61 = (a309 - a310);
        s62 = (a309 + a310);
        a311 = (a301 + 16);
        a312 = (a301 + 17);
        a313 = (a301 + 48);
        a314 = (a301 + 49);
        t187 = (*((X + a311)) + *((X + a313)));
        t188 = (*((X + a312)) + *((X + a314)));
        t189 = (*((X + a311)) - *((X + a313)));
        t190 = (*((X + a312)) - *((X + a314)));
        a315 = (a301 + 24);
        a316 = (a301 + 25);
        a317 = (a301 + 56);
        a318 = (a301 + 57);
        t191 = (*((X + a315)) + *((X + a317)));
        t192 = (*((X + a316)) + *((X + a318)));
        a319 = (0.70710678118654757*(*((X + a315)) - *((X + a317))));
        a320 = (0.70710678118654757*(*((X + a316)) - *((X + a318))));
        s63 = (a319 + a320);
        s64 = (a319 - a320);
        t193 = (t181 + t187);
        t194 = (t182 + t188);
        t195 = (t181 - t187);
        t196 = (t182 - t188);
        t197 = (t185 + t191);
        t198 = (t186 + t192);
        t199 = (t185 - t191);
        t200 = (t186 - t192);
        t201 = (t193 + t197);
        t202 = (t194 + t198);
        t203 = (t193 - t197);
        t204 = (t194 - t198);
        a321 = (16*i3);
        a322 = (a321 + 1);
        a323 = (a321 + 2);
        a324 = (a321 + 3);
        *((T1 + a321)) = ((*((D1 + a321))*t201) - (*((D1 + a322))*t202));
        *((T1 + a322)) = ((*((D1 + a322))*t201) + (*((D1 + a321))*t202));
        a325 = (a321 + 8);
        *((T1 + a325)) = ((*((D1 + a323))*t203) - (*((D1 + a324))*t204));
        a326 = (a321 + 9);
        *((T1 + a326)) = ((*((D1 + a324))*t203) + (*((D1 + a323))*t204));
        t205 = (t195 - t200);
        t206 = (t196 + t199);
        t207 = (t195 + t200);
        t208 = (t196 - t199);
        a327 = (a321 + 4);
        a328 = (a321 + 5);
        a329 = (a321 + 6);
        a330 = (a321 + 7);
        *((T1 + a327)) = ((*((D1 + a327))*t205) - (*((D1 + a328))*t206));
        *((T1 + a328)) = ((*((D1 + a328))*t205) + (*((D1 + a327))*t206));
        a331 = (a321 + 12);
        *((T1 + a331)) = ((*((D1 + a329))*t207) - (*((D1 + a330))*t208));
        a332 = (a321 + 13);
        *((T1 + a332)) = ((*((D1 + a330))*t207) + (*((D1 + a329))*t208));
        t209 = (t183 - t190);
        t210 = (t184 + t189);
        t211 = (t183 + t190);
        t212 = (t184 - t189);
        t213 = (s61 - s63);
        t214 = (s62 + s64);
        t215 = (s61 + s63);
        t216 = (s62 - s64);
        t217 = (t209 + t213);
        t218 = (t210 + t214);
        t219 = (t209 - t213);
        t220 = (t210 - t214);
        a333 = (a321 + 10);
        a334 = (a321 + 11);
        *((T1 + a323)) = ((*((D1 + a325))*t217) - (*((D1 + a326))*t218));
        *((T1 + a324)) = ((*((D1 + a326))*t217) + (*((D1 + a325))*t218));
        *((T1 + a333)) = ((*((D1 + a333))*t219) - (*((D1 + a334))*t220));
        *((T1 + a334)) = ((*((D1 + a334))*t219) + (*((D1 + a333))*t220));
        t221 = (t211 - t216);
        t222 = (t212 + t215);
        t223 = (t211 + t216);
        t224 = (t212 - t215);
        a335 = (a321 + 14);
        a336 = (a321 + 15);
        *((T1 + a329)) = ((*((D1 + a331))*t221) - (*((D1 + a332))*t222));
        *((T1 + a330)) = ((*((D1 + a332))*t221) + (*((D1 + a331))*t222));
        *((T1 + a335)) = ((*((D1 + a335))*t223) - (*((D1 + a336))*t224));
        *((T1 + a336)) = ((*((D1 + a336))*t223) + (*((D1 + a335))*t224));
    }
    for(int i2 = 0; i2 <= 7; i2++) {
        int a383, a384, a385, a387, a388, a389, a390, a391;
        f64i_gal t265, t266, t267, t268, t269, t270, t271, t272;
        a383 = (2*i2);
        a384 = (a383 + 1);
        a385 = (a383 + 32);
        a387 = (a383 + 33);
        t265 = (*((T1 + a383)) + *((T1 + a385)));
        t266 = (*((T1 + a384)) + *((T1 + a387)));
        t267 = (*((T1 + a383)) - *((T1 + a385)));
        t268 = (*((T1 + a384)) - *((T1 + a387)));
        a388 = (a383 + 16);
        a389 = (a383 + 17);
        a390 = (a383 + 48);
        a391 = (a383 + 49);
        t269 = (*((T1 + a388)) + *((T1 + a390)));
        t270 = (*((T1 + a389)) + *((T1 + a391)));
        t271 = (*((T1 + a388)) - *((T1 + a390)));
        t272 = (*((T1 + a389)) - *((T1 + a391)));
        *((Y + a383)) = (t265 + t269);
        *((Y + a384)) = (t266 + t270);
        *((Y + a385)) = (t265 - t269);
        *((Y + a387)) = (t266 - t270);
        *((Y + a388)) = (t267 - t272);
        *((Y + a389)) = (t268 + t271);
        *((Y + a390)) = (t267 + t272);
        *((Y + a391)) = (t268 - t271);
    }
}
