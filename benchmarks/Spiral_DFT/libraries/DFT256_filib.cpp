#include "filib_common.h"

f64i_fil cospi(f64i_fil x);
f64i_fil sinpi(f64i_fil x);
static f64i_fil D1[512];

void init_DFT256_fil() {
    for(int i3 = 0; i3 <= 15; i3++) {
        for(int i10 = 0; i10 <= 7; i10++) {
            D1[((32*i3) + (4*i10))] = cospi((((f64i_fil )(2*(i3*i10))) / 256.));
            D1[(1 + (32*i3) + (4*i10))] = sinpi((((f64i_fil )(2*(((2*(i3*i10)) + 1) / 2))) / 256.));
            D1[(2 + (32*i3) + (4*i10))] = cospi((((f64i_fil )(2*(i3*(8 + i10)))) / 256.));
            D1[(3 + (32*i3) + (4*i10))] = sinpi((((f64i_fil )(2*(((2*(i3*(8 + i10))) + 1) / 2))) / 256.));
        }
    }
}

void DFT256(f64i_fil  *Y, f64i_fil  *X) {
    static f64i_fil T1[512];
    for(int i3 = 0; i3 <= 15; i3++) {
        int a654, a655, a656, a657, a658, a659, a660, a661
                , a664, a665, a666, a667, a668, a669, a670, a671
                , a674, a675, a676, a677, a678, a679, a680, a681
                , a684, a685, a686, a687, a688, a689, a690, a691
                , a698, a699, a700, a701, a702, a703, a704, a705
                , a706, a707, a708, a709, a710, a711, a712, a713
                , a714, a715, a716, a717, a718, a719, a720, a721
                , a722, a723, a724, a725, a726, a727, a728, a729;
        f64i_fil a662, a663, a672, a673, a682, a683, a692, a693
                , a694, a695, a696, a697, s157, s158, s159, s160
                , s161, s162, s163, s164, s165, s166, s167, s168
                , s169, s170, s171, s172, s173, s174, s175, s176
                , t438, t439, t440, t441, t442, t443, t444, t445
                , t446, t447, t448, t449, t450, t451, t452, t453
                , t454, t455, t456, t457, t458, t459, t460, t461
                , t462, t463, t464, t465, t466, t467, t468, t469
                , t470, t471, t472, t473, t474, t475, t476, t477
                , t478, t479, t480, t481, t482, t483, t484, t485
                , t486, t487, t488, t489, t490, t491, t492, t493
                , t494, t495, t496, t497, t498, t499, t500, t501
                , t502, t503, t504, t505, t506, t507, t508, t509
                , t510, t511, t512, t513, t514, t515, t516, t517
                , t518, t519, t520, t521, t522, t523, t524, t525
                , t526, t527, t528, t529, t530, t531, t532, t533
                , t534, t535, t536, t537, t538, t539, t540, t541
                , t542, t543, t544, t545, t546, t547, t548, t549
                , t550, t551, t552, t553;
        a654 = (2*i3);
        a655 = (a654 + 1);
        a656 = (a654 + 256);
        a657 = (a654 + 257);
        t438 = (*((X + a654)) + *((X + a656)));
        t439 = (*((X + a655)) + *((X + a657)));
        t440 = (*((X + a654)) - *((X + a656)));
        t441 = (*((X + a655)) - *((X + a657)));
        a658 = (a654 + 64);
        a659 = (a654 + 65);
        a660 = (a654 + 320);
        a661 = (a654 + 321);
        t442 = (*((X + a658)) + *((X + a660)));
        t443 = (*((X + a659)) + *((X + a661)));
        a662 = (0.70710678118654757*(*((X + a658)) - *((X + a660))));
        a663 = (0.70710678118654757*(*((X + a659)) - *((X + a661))));
        s157 = (a662 - a663);
        s158 = (a662 + a663);
        a664 = (a654 + 128);
        a665 = (a654 + 129);
        a666 = (a654 + 384);
        a667 = (a654 + 385);
        t444 = (*((X + a664)) + *((X + a666)));
        t445 = (*((X + a665)) + *((X + a667)));
        t446 = (*((X + a664)) - *((X + a666)));
        t447 = (*((X + a665)) - *((X + a667)));
        a668 = (a654 + 192);
        a669 = (a654 + 193);
        a670 = (a654 + 448);
        a671 = (a654 + 449);
        t448 = (*((X + a668)) + *((X + a670)));
        t449 = (*((X + a669)) + *((X + a671)));
        a672 = (0.70710678118654757*(*((X + a668)) - *((X + a670))));
        a673 = (0.70710678118654757*(*((X + a669)) - *((X + a671))));
        s159 = (a672 + a673);
        s160 = (a672 - a673);
        t450 = (t438 + t444);
        t451 = (t439 + t445);
        t452 = (t438 - t444);
        t453 = (t439 - t445);
        t454 = (t442 + t448);
        t455 = (t443 + t449);
        t456 = (t442 - t448);
        t457 = (t443 - t449);
        t458 = (t450 + t454);
        t459 = (t451 + t455);
        t460 = (t450 - t454);
        t461 = (t451 - t455);
        t462 = (t452 - t457);
        t463 = (t453 + t456);
        t464 = (t452 + t457);
        t465 = (t453 - t456);
        t466 = (t440 - t447);
        t467 = (t441 + t446);
        t468 = (t440 + t447);
        t469 = (t441 - t446);
        t470 = (s157 - s159);
        t471 = (s158 + s160);
        t472 = (s157 + s159);
        t473 = (s158 - s160);
        t474 = (t466 + t470);
        t475 = (t467 + t471);
        t476 = (t466 - t470);
        t477 = (t467 - t471);
        t478 = (t468 - t473);
        t479 = (t469 + t472);
        t480 = (t468 + t473);
        t481 = (t469 - t472);
        a674 = (a654 + 32);
        a675 = (a654 + 33);
        a676 = (a654 + 288);
        a677 = (a654 + 289);
        t482 = (*((X + a674)) + *((X + a676)));
        t483 = (*((X + a675)) + *((X + a677)));
        t484 = (*((X + a674)) - *((X + a676)));
        t485 = (*((X + a675)) - *((X + a677)));
        a678 = (a654 + 96);
        a679 = (a654 + 97);
        a680 = (a654 + 352);
        a681 = (a654 + 353);
        t486 = (*((X + a678)) + *((X + a680)));
        t487 = (*((X + a679)) + *((X + a681)));
        a682 = (0.70710678118654757*(*((X + a678)) - *((X + a680))));
        a683 = (0.70710678118654757*(*((X + a679)) - *((X + a681))));
        s161 = (a682 - a683);
        s162 = (a682 + a683);
        a684 = (a654 + 160);
        a685 = (a654 + 161);
        a686 = (a654 + 416);
        a687 = (a654 + 417);
        t488 = (*((X + a684)) + *((X + a686)));
        t489 = (*((X + a685)) + *((X + a687)));
        t490 = (*((X + a684)) - *((X + a686)));
        t491 = (*((X + a685)) - *((X + a687)));
        a688 = (a654 + 224);
        a689 = (a654 + 225);
        a690 = (a654 + 480);
        a691 = (a654 + 481);
        t492 = (*((X + a688)) + *((X + a690)));
        t493 = (*((X + a689)) + *((X + a691)));
        a692 = (0.70710678118654757*(*((X + a688)) - *((X + a690))));
        a693 = (0.70710678118654757*(*((X + a689)) - *((X + a691))));
        s163 = (a692 + a693);
        s164 = (a692 - a693);
        t494 = (t482 + t488);
        t495 = (t483 + t489);
        t496 = (t482 - t488);
        t497 = (t483 - t489);
        t498 = (t486 + t492);
        t499 = (t487 + t493);
        t500 = (t486 - t492);
        t501 = (t487 - t493);
        t502 = (t494 + t498);
        t503 = (t495 + t499);
        t504 = (t494 - t498);
        t505 = (t495 - t499);
        a694 = (0.70710678118654757*(t496 - t501));
        a695 = (0.70710678118654757*(t497 + t500));
        s165 = (a694 - a695);
        s166 = (a694 + a695);
        a696 = (0.70710678118654757*(t496 + t501));
        a697 = (0.70710678118654757*(t497 - t500));
        s167 = (a696 + a697);
        s168 = (a696 - a697);
        t506 = (t484 - t491);
        t507 = (t485 + t490);
        t508 = (t484 + t491);
        t509 = (t485 - t490);
        t510 = (s161 - s163);
        t511 = (s162 + s164);
        t512 = (s161 + s163);
        t513 = (s162 - s164);
        t514 = (t506 + t510);
        t515 = (t507 + t511);
        t516 = (t506 - t510);
        t517 = (t507 - t511);
        s169 = ((0.92387953251128674*t514) - (0.38268343236508978*t515));
        s170 = ((0.38268343236508978*t514) + (0.92387953251128674*t515));
        s171 = ((0.38268343236508978*t516) + (0.92387953251128674*t517));
        s172 = ((0.92387953251128674*t516) - (0.38268343236508978*t517));
        t518 = (t508 - t513);
        t519 = (t509 + t512);
        t520 = (t508 + t513);
        t521 = (t509 - t512);
        s173 = ((0.38268343236508978*t518) - (0.92387953251128674*t519));
        s174 = ((0.92387953251128674*t518) + (0.38268343236508978*t519));
        s175 = ((0.92387953251128674*t520) + (0.38268343236508978*t521));
        s176 = ((0.38268343236508978*t520) - (0.92387953251128674*t521));
        t522 = (t458 + t502);
        t523 = (t459 + t503);
        t524 = (t458 - t502);
        t525 = (t459 - t503);
        a698 = (32*i3);
        a699 = (a698 + 1);
        a700 = (a698 + 2);
        a701 = (a698 + 3);
        *((T1 + a698)) = ((*((D1 + a698))*t522) - (*((D1 + a699))*t523));
        *((T1 + a699)) = ((*((D1 + a699))*t522) + (*((D1 + a698))*t523));
        a702 = (a698 + 16);
        *((T1 + a702)) = ((*((D1 + a700))*t524) - (*((D1 + a701))*t525));
        a703 = (a698 + 17);
        *((T1 + a703)) = ((*((D1 + a701))*t524) + (*((D1 + a700))*t525));
        t526 = (t474 + s169);
        t527 = (t475 + s170);
        t528 = (t474 - s169);
        t529 = (t475 - s170);
        a704 = (a698 + 4);
        a705 = (a698 + 5);
        a706 = (a698 + 6);
        a707 = (a698 + 7);
        *((T1 + a700)) = ((*((D1 + a704))*t526) - (*((D1 + a705))*t527));
        *((T1 + a701)) = ((*((D1 + a705))*t526) + (*((D1 + a704))*t527));
        a708 = (a698 + 18);
        *((T1 + a708)) = ((*((D1 + a706))*t528) - (*((D1 + a707))*t529));
        a709 = (a698 + 19);
        *((T1 + a709)) = ((*((D1 + a707))*t528) + (*((D1 + a706))*t529));
        t530 = (t462 + s165);
        t531 = (t463 + s166);
        t532 = (t462 - s165);
        t533 = (t463 - s166);
        a710 = (a698 + 8);
        a711 = (a698 + 9);
        a712 = (a698 + 10);
        a713 = (a698 + 11);
        *((T1 + a704)) = ((*((D1 + a710))*t530) - (*((D1 + a711))*t531));
        *((T1 + a705)) = ((*((D1 + a711))*t530) + (*((D1 + a710))*t531));
        a714 = (a698 + 20);
        *((T1 + a714)) = ((*((D1 + a712))*t532) - (*((D1 + a713))*t533));
        a715 = (a698 + 21);
        *((T1 + a715)) = ((*((D1 + a713))*t532) + (*((D1 + a712))*t533));
        t534 = (t478 + s173);
        t535 = (t479 + s174);
        t536 = (t478 - s173);
        t537 = (t479 - s174);
        a716 = (a698 + 12);
        a717 = (a698 + 13);
        a718 = (a698 + 14);
        a719 = (a698 + 15);
        *((T1 + a706)) = ((*((D1 + a716))*t534) - (*((D1 + a717))*t535));
        *((T1 + a707)) = ((*((D1 + a717))*t534) + (*((D1 + a716))*t535));
        a720 = (a698 + 22);
        *((T1 + a720)) = ((*((D1 + a718))*t536) - (*((D1 + a719))*t537));
        a721 = (a698 + 23);
        *((T1 + a721)) = ((*((D1 + a719))*t536) + (*((D1 + a718))*t537));
        t538 = (t460 - t505);
        t539 = (t461 + t504);
        t540 = (t460 + t505);
        t541 = (t461 - t504);
        *((T1 + a710)) = ((*((D1 + a702))*t538) - (*((D1 + a703))*t539));
        *((T1 + a711)) = ((*((D1 + a703))*t538) + (*((D1 + a702))*t539));
        a722 = (a698 + 24);
        *((T1 + a722)) = ((*((D1 + a708))*t540) - (*((D1 + a709))*t541));
        a723 = (a698 + 25);
        *((T1 + a723)) = ((*((D1 + a709))*t540) + (*((D1 + a708))*t541));
        t542 = (t476 - s171);
        t543 = (t477 + s172);
        t544 = (t476 + s171);
        t545 = (t477 - s172);
        *((T1 + a712)) = ((*((D1 + a714))*t542) - (*((D1 + a715))*t543));
        *((T1 + a713)) = ((*((D1 + a715))*t542) + (*((D1 + a714))*t543));
        a724 = (a698 + 26);
        *((T1 + a724)) = ((*((D1 + a720))*t544) - (*((D1 + a721))*t545));
        a725 = (a698 + 27);
        *((T1 + a725)) = ((*((D1 + a721))*t544) + (*((D1 + a720))*t545));
        t546 = (t464 - s167);
        t547 = (t465 + s168);
        t548 = (t464 + s167);
        t549 = (t465 - s168);
        *((T1 + a716)) = ((*((D1 + a722))*t546) - (*((D1 + a723))*t547));
        *((T1 + a717)) = ((*((D1 + a723))*t546) + (*((D1 + a722))*t547));
        a726 = (a698 + 28);
        *((T1 + a726)) = ((*((D1 + a724))*t548) - (*((D1 + a725))*t549));
        a727 = (a698 + 29);
        *((T1 + a727)) = ((*((D1 + a725))*t548) + (*((D1 + a724))*t549));
        t550 = (t480 - s175);
        t551 = (t481 + s176);
        t552 = (t480 + s175);
        t553 = (t481 - s176);
        a728 = (a698 + 30);
        a729 = (a698 + 31);
        *((T1 + a718)) = ((*((D1 + a726))*t550) - (*((D1 + a727))*t551));
        *((T1 + a719)) = ((*((D1 + a727))*t550) + (*((D1 + a726))*t551));
        *((T1 + a728)) = ((*((D1 + a728))*t552) - (*((D1 + a729))*t553));
        *((T1 + a729)) = ((*((D1 + a729))*t552) + (*((D1 + a728))*t553));
    }
    for(int i2 = 0; i2 <= 15; i2++) {
        int a1000, a1001, a1002, a1003, a1004, a1005, a1006, a1007
                , a1010, a1011, a1012, a1013, a1014, a1015, a1016, a1017
                , a1020, a1021, a1022, a1023, a1024, a1025, a1026, a1027
                , a1030, a1031, a1032, a1033, a1034, a1035, a1036, a1037;
        f64i_fil a1008, a1009, a1018, a1019, a1028, a1029, a1038, a1039
                , a1040, a1041, a1042, a1043, s269, s270, s271, s272
                , s273, s274, s275, s276, s277, s278, s279, s280
                , s281, s282, s283, s284, s285, s286, s287, s288
                , t894, t895, t896, t897, t898, t899, t900, t901
                , t902, t903, t904, t905, t906, t907, t908, t909
                , t910, t911, t912, t913, t914, t915, t916, t917
                , t918, t919, t920, t921, t922, t923, t924, t925
                , t926, t927, t928, t929, t930, t931, t932, t933
                , t934, t935, t936, t937, t938, t939, t940, t941
                , t942, t943, t944, t945, t946, t947, t948, t949
                , t950, t951, t952, t953, t954, t955, t956, t957
                , t958, t959, t960, t961, t962, t963, t964, t965
                , t966, t967, t968, t969, t970, t971, t972, t973
                , t974, t975, t976, t977;
        a1000 = (2*i2);
        a1001 = (a1000 + 1);
        a1002 = (a1000 + 256);
        a1003 = (a1000 + 257);
        t894 = (*((T1 + a1000)) + *((T1 + a1002)));
        t895 = (*((T1 + a1001)) + *((T1 + a1003)));
        t896 = (*((T1 + a1000)) - *((T1 + a1002)));
        t897 = (*((T1 + a1001)) - *((T1 + a1003)));
        a1004 = (a1000 + 64);
        a1005 = (a1000 + 65);
        a1006 = (a1000 + 320);
        a1007 = (a1000 + 321);
        t898 = (*((T1 + a1004)) + *((T1 + a1006)));
        t899 = (*((T1 + a1005)) + *((T1 + a1007)));
        a1008 = (0.70710678118654757*(*((T1 + a1004)) - *((T1 + a1006))));
        a1009 = (0.70710678118654757*(*((T1 + a1005)) - *((T1 + a1007))));
        s269 = (a1008 - a1009);
        s270 = (a1008 + a1009);
        a1010 = (a1000 + 128);
        a1011 = (a1000 + 129);
        a1012 = (a1000 + 384);
        a1013 = (a1000 + 385);
        t900 = (*((T1 + a1010)) + *((T1 + a1012)));
        t901 = (*((T1 + a1011)) + *((T1 + a1013)));
        t902 = (*((T1 + a1010)) - *((T1 + a1012)));
        t903 = (*((T1 + a1011)) - *((T1 + a1013)));
        a1014 = (a1000 + 192);
        a1015 = (a1000 + 193);
        a1016 = (a1000 + 448);
        a1017 = (a1000 + 449);
        t904 = (*((T1 + a1014)) + *((T1 + a1016)));
        t905 = (*((T1 + a1015)) + *((T1 + a1017)));
        a1018 = (0.70710678118654757*(*((T1 + a1014)) - *((T1 + a1016))));
        a1019 = (0.70710678118654757*(*((T1 + a1015)) - *((T1 + a1017))));
        s271 = (a1018 + a1019);
        s272 = (a1018 - a1019);
        t906 = (t894 + t900);
        t907 = (t895 + t901);
        t908 = (t894 - t900);
        t909 = (t895 - t901);
        t910 = (t898 + t904);
        t911 = (t899 + t905);
        t912 = (t898 - t904);
        t913 = (t899 - t905);
        t914 = (t906 + t910);
        t915 = (t907 + t911);
        t916 = (t906 - t910);
        t917 = (t907 - t911);
        t918 = (t908 - t913);
        t919 = (t909 + t912);
        t920 = (t908 + t913);
        t921 = (t909 - t912);
        t922 = (t896 - t903);
        t923 = (t897 + t902);
        t924 = (t896 + t903);
        t925 = (t897 - t902);
        t926 = (s269 - s271);
        t927 = (s270 + s272);
        t928 = (s269 + s271);
        t929 = (s270 - s272);
        t930 = (t922 + t926);
        t931 = (t923 + t927);
        t932 = (t922 - t926);
        t933 = (t923 - t927);
        t934 = (t924 - t929);
        t935 = (t925 + t928);
        t936 = (t924 + t929);
        t937 = (t925 - t928);
        a1020 = (a1000 + 32);
        a1021 = (a1000 + 33);
        a1022 = (a1000 + 288);
        a1023 = (a1000 + 289);
        t938 = (*((T1 + a1020)) + *((T1 + a1022)));
        t939 = (*((T1 + a1021)) + *((T1 + a1023)));
        t940 = (*((T1 + a1020)) - *((T1 + a1022)));
        t941 = (*((T1 + a1021)) - *((T1 + a1023)));
        a1024 = (a1000 + 96);
        a1025 = (a1000 + 97);
        a1026 = (a1000 + 352);
        a1027 = (a1000 + 353);
        t942 = (*((T1 + a1024)) + *((T1 + a1026)));
        t943 = (*((T1 + a1025)) + *((T1 + a1027)));
        a1028 = (0.70710678118654757*(*((T1 + a1024)) - *((T1 + a1026))));
        a1029 = (0.70710678118654757*(*((T1 + a1025)) - *((T1 + a1027))));
        s273 = (a1028 - a1029);
        s274 = (a1028 + a1029);
        a1030 = (a1000 + 160);
        a1031 = (a1000 + 161);
        a1032 = (a1000 + 416);
        a1033 = (a1000 + 417);
        t944 = (*((T1 + a1030)) + *((T1 + a1032)));
        t945 = (*((T1 + a1031)) + *((T1 + a1033)));
        t946 = (*((T1 + a1030)) - *((T1 + a1032)));
        t947 = (*((T1 + a1031)) - *((T1 + a1033)));
        a1034 = (a1000 + 224);
        a1035 = (a1000 + 225);
        a1036 = (a1000 + 480);
        a1037 = (a1000 + 481);
        t948 = (*((T1 + a1034)) + *((T1 + a1036)));
        t949 = (*((T1 + a1035)) + *((T1 + a1037)));
        a1038 = (0.70710678118654757*(*((T1 + a1034)) - *((T1 + a1036))));
        a1039 = (0.70710678118654757*(*((T1 + a1035)) - *((T1 + a1037))));
        s275 = (a1038 + a1039);
        s276 = (a1038 - a1039);
        t950 = (t938 + t944);
        t951 = (t939 + t945);
        t952 = (t938 - t944);
        t953 = (t939 - t945);
        t954 = (t942 + t948);
        t955 = (t943 + t949);
        t956 = (t942 - t948);
        t957 = (t943 - t949);
        t958 = (t950 + t954);
        t959 = (t951 + t955);
        t960 = (t950 - t954);
        t961 = (t951 - t955);
        a1040 = (0.70710678118654757*(t952 - t957));
        a1041 = (0.70710678118654757*(t953 + t956));
        s277 = (a1040 - a1041);
        s278 = (a1040 + a1041);
        a1042 = (0.70710678118654757*(t952 + t957));
        a1043 = (0.70710678118654757*(t953 - t956));
        s279 = (a1042 + a1043);
        s280 = (a1042 - a1043);
        t962 = (t940 - t947);
        t963 = (t941 + t946);
        t964 = (t940 + t947);
        t965 = (t941 - t946);
        t966 = (s273 - s275);
        t967 = (s274 + s276);
        t968 = (s273 + s275);
        t969 = (s274 - s276);
        t970 = (t962 + t966);
        t971 = (t963 + t967);
        t972 = (t962 - t966);
        t973 = (t963 - t967);
        s281 = ((0.92387953251128674*t970) - (0.38268343236508978*t971));
        s282 = ((0.38268343236508978*t970) + (0.92387953251128674*t971));
        s283 = ((0.38268343236508978*t972) + (0.92387953251128674*t973));
        s284 = ((0.92387953251128674*t972) - (0.38268343236508978*t973));
        t974 = (t964 - t969);
        t975 = (t965 + t968);
        t976 = (t964 + t969);
        t977 = (t965 - t968);
        s285 = ((0.38268343236508978*t974) - (0.92387953251128674*t975));
        s286 = ((0.92387953251128674*t974) + (0.38268343236508978*t975));
        s287 = ((0.92387953251128674*t976) + (0.38268343236508978*t977));
        s288 = ((0.38268343236508978*t976) - (0.92387953251128674*t977));
        *((Y + a1000)) = (t914 + t958);
        *((Y + a1001)) = (t915 + t959);
        *((Y + a1002)) = (t914 - t958);
        *((Y + a1003)) = (t915 - t959);
        *((Y + a1020)) = (t930 + s281);
        *((Y + a1021)) = (t931 + s282);
        *((Y + a1022)) = (t930 - s281);
        *((Y + a1023)) = (t931 - s282);
        *((Y + a1004)) = (t918 + s277);
        *((Y + a1005)) = (t919 + s278);
        *((Y + a1006)) = (t918 - s277);
        *((Y + a1007)) = (t919 - s278);
        *((Y + a1024)) = (t934 + s285);
        *((Y + a1025)) = (t935 + s286);
        *((Y + a1026)) = (t934 - s285);
        *((Y + a1027)) = (t935 - s286);
        *((Y + a1010)) = (t916 - t961);
        *((Y + a1011)) = (t917 + t960);
        *((Y + a1012)) = (t916 + t961);
        *((Y + a1013)) = (t917 - t960);
        *((Y + a1030)) = (t932 - s283);
        *((Y + a1031)) = (t933 + s284);
        *((Y + a1032)) = (t932 + s283);
        *((Y + a1033)) = (t933 - s284);
        *((Y + a1014)) = (t920 - s279);
        *((Y + a1015)) = (t921 + s280);
        *((Y + a1016)) = (t920 + s279);
        *((Y + a1017)) = (t921 - s280);
        *((Y + a1034)) = (t936 - s287);
        *((Y + a1035)) = (t937 + s288);
        *((Y + a1036)) = (t936 + s287);
        *((Y + a1037)) = (t937 - s288);
    }
}
