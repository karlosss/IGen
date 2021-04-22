#pragma once

#define mm256_insertf128_pd_VERIFY(NAME) \
    static void mm256_insertf128_pd_ ## NAME ## _verify() { \
        ddi_4 a0 = _igen_dd_fb_mm256_load_pd(in_ddi); \
        ddi_4 a1 = _igen_dd_fb_mm256_load_pd(in_ddi+4); \
        ddi_4 a2 = _igen_dd_fb_mm256_load_pd(in_ddi+8); \
        ddi_4 a3 = _igen_dd_fb_mm256_load_pd(in_ddi+12); \
        ddi_4 a4 = _igen_dd_fb_mm256_load_pd(in_ddi+16); \
        ddi_4 a5 = _igen_dd_fb_mm256_load_pd(in_ddi+20); \
        ddi_4 a6 = _igen_dd_fb_mm256_load_pd(in_ddi+24); \
        ddi_4 a7 = _igen_dd_fb_mm256_load_pd(in_ddi+28); \
        ddi_4 a8 = _igen_dd_fb_mm256_load_pd(in_ddi+32); \
        ddi_4 a9 = _igen_dd_fb_mm256_load_pd(in_ddi+36); \
        ddi_4 a10 = _igen_dd_fb_mm256_load_pd(in_ddi+40); \
        ddi_4 a11 = _igen_dd_fb_mm256_load_pd(in_ddi+44); \
        ddi_4 a12 = _igen_dd_fb_mm256_load_pd(in_ddi+48); \
        ddi_4 a13 = _igen_dd_fb_mm256_load_pd(in_ddi+52); \
        ddi_4 a14 = _igen_dd_fb_mm256_load_pd(in_ddi+56); \
        ddi_4 a15 = _igen_dd_fb_mm256_load_pd(in_ddi+60); \
        ddi_4 a16 = _igen_dd_fb_mm256_load_pd(in_ddi+64); \
        ddi_4 a17 = _igen_dd_fb_mm256_load_pd(in_ddi+68); \
        ddi_4 a18 = _igen_dd_fb_mm256_load_pd(in_ddi+72); \
        ddi_4 a19 = _igen_dd_fb_mm256_load_pd(in_ddi+76); \
        ddi_4 a20 = _igen_dd_fb_mm256_load_pd(in_ddi+80); \
        ddi_4 a21 = _igen_dd_fb_mm256_load_pd(in_ddi+84); \
        ddi_4 a22 = _igen_dd_fb_mm256_load_pd(in_ddi+88); \
        ddi_4 a23 = _igen_dd_fb_mm256_load_pd(in_ddi+92); \
        ddi_4 a24 = _igen_dd_fb_mm256_load_pd(in_ddi+96); \
        ddi_4 a25 = _igen_dd_fb_mm256_load_pd(in_ddi+100); \
        ddi_4 a26 = _igen_dd_fb_mm256_load_pd(in_ddi+104); \
        ddi_4 a27 = _igen_dd_fb_mm256_load_pd(in_ddi+108); \
        ddi_4 a28 = _igen_dd_fb_mm256_load_pd(in_ddi+112); \
        ddi_4 a29 = _igen_dd_fb_mm256_load_pd(in_ddi+116); \
        ddi_4 a30 = _igen_dd_fb_mm256_load_pd(in_ddi+120); \
        ddi_4 a31 = _igen_dd_fb_mm256_load_pd(in_ddi+124); \
        ddi_4 a32 = _igen_dd_fb_mm256_load_pd(in_ddi+128); \
        ddi_4 a33 = _igen_dd_fb_mm256_load_pd(in_ddi+132); \
        ddi_4 a34 = _igen_dd_fb_mm256_load_pd(in_ddi+136); \
        ddi_4 a35 = _igen_dd_fb_mm256_load_pd(in_ddi+140); \
        ddi_4 a36 = _igen_dd_fb_mm256_load_pd(in_ddi+144); \
        ddi_4 a37 = _igen_dd_fb_mm256_load_pd(in_ddi+148); \
        ddi_4 a38 = _igen_dd_fb_mm256_load_pd(in_ddi+152); \
        ddi_4 a39 = _igen_dd_fb_mm256_load_pd(in_ddi+156); \
        ddi_4 a40 = _igen_dd_fb_mm256_load_pd(in_ddi+160); \
        ddi_4 a41 = _igen_dd_fb_mm256_load_pd(in_ddi+164); \
        ddi_4 a42 = _igen_dd_fb_mm256_load_pd(in_ddi+168); \
        ddi_4 a43 = _igen_dd_fb_mm256_load_pd(in_ddi+172); \
        ddi_4 a44 = _igen_dd_fb_mm256_load_pd(in_ddi+176); \
        ddi_4 a45 = _igen_dd_fb_mm256_load_pd(in_ddi+180); \
        ddi_4 a46 = _igen_dd_fb_mm256_load_pd(in_ddi+184); \
        ddi_4 a47 = _igen_dd_fb_mm256_load_pd(in_ddi+188); \
        ddi_4 a48 = _igen_dd_fb_mm256_load_pd(in_ddi+192); \
        ddi_4 a49 = _igen_dd_fb_mm256_load_pd(in_ddi+196); \
        ddi_4 a50 = _igen_dd_fb_mm256_load_pd(in_ddi+200); \
        ddi_4 a51 = _igen_dd_fb_mm256_load_pd(in_ddi+204); \
        ddi_4 a52 = _igen_dd_fb_mm256_load_pd(in_ddi+208); \
        ddi_4 a53 = _igen_dd_fb_mm256_load_pd(in_ddi+212); \
        ddi_4 a54 = _igen_dd_fb_mm256_load_pd(in_ddi+216); \
        ddi_4 a55 = _igen_dd_fb_mm256_load_pd(in_ddi+220); \
        ddi_4 a56 = _igen_dd_fb_mm256_load_pd(in_ddi+224); \
        ddi_4 a57 = _igen_dd_fb_mm256_load_pd(in_ddi+228); \
        ddi_4 a58 = _igen_dd_fb_mm256_load_pd(in_ddi+232); \
        ddi_4 a59 = _igen_dd_fb_mm256_load_pd(in_ddi+236); \
        ddi_4 a60 = _igen_dd_fb_mm256_load_pd(in_ddi+240); \
        ddi_4 a61 = _igen_dd_fb_mm256_load_pd(in_ddi+244); \
        ddi_4 a62 = _igen_dd_fb_mm256_load_pd(in_ddi+248); \
        ddi_4 a63 = _igen_dd_fb_mm256_load_pd(in_ddi+252); \
        ddi_4 a64 = _igen_dd_fb_mm256_load_pd(in_ddi+256); \
        ddi_4 a65 = _igen_dd_fb_mm256_load_pd(in_ddi+260); \
        ddi_4 a66 = _igen_dd_fb_mm256_load_pd(in_ddi+264); \
        ddi_4 a67 = _igen_dd_fb_mm256_load_pd(in_ddi+268); \
        ddi_4 a68 = _igen_dd_fb_mm256_load_pd(in_ddi+272); \
        ddi_4 a69 = _igen_dd_fb_mm256_load_pd(in_ddi+276); \
        ddi_4 a70 = _igen_dd_fb_mm256_load_pd(in_ddi+280); \
        ddi_4 a71 = _igen_dd_fb_mm256_load_pd(in_ddi+284); \
        ddi_4 a72 = _igen_dd_fb_mm256_load_pd(in_ddi+288); \
        ddi_4 a73 = _igen_dd_fb_mm256_load_pd(in_ddi+292); \
        ddi_4 a74 = _igen_dd_fb_mm256_load_pd(in_ddi+296); \
        ddi_4 a75 = _igen_dd_fb_mm256_load_pd(in_ddi+300); \
        ddi_4 a76 = _igen_dd_fb_mm256_load_pd(in_ddi+304); \
        ddi_4 a77 = _igen_dd_fb_mm256_load_pd(in_ddi+308); \
        ddi_4 a78 = _igen_dd_fb_mm256_load_pd(in_ddi+312); \
        ddi_4 a79 = _igen_dd_fb_mm256_load_pd(in_ddi+316); \
        ddi_4 a80 = _igen_dd_fb_mm256_load_pd(in_ddi+320); \
        ddi_4 a81 = _igen_dd_fb_mm256_load_pd(in_ddi+324); \
        ddi_4 a82 = _igen_dd_fb_mm256_load_pd(in_ddi+328); \
        ddi_4 a83 = _igen_dd_fb_mm256_load_pd(in_ddi+332); \
        ddi_4 a84 = _igen_dd_fb_mm256_load_pd(in_ddi+336); \
        ddi_4 a85 = _igen_dd_fb_mm256_load_pd(in_ddi+340); \
        ddi_4 a86 = _igen_dd_fb_mm256_load_pd(in_ddi+344); \
        ddi_4 a87 = _igen_dd_fb_mm256_load_pd(in_ddi+348); \
        ddi_4 a88 = _igen_dd_fb_mm256_load_pd(in_ddi+352); \
        ddi_4 a89 = _igen_dd_fb_mm256_load_pd(in_ddi+356); \
        ddi_4 a90 = _igen_dd_fb_mm256_load_pd(in_ddi+360); \
        ddi_4 a91 = _igen_dd_fb_mm256_load_pd(in_ddi+364); \
        ddi_4 a92 = _igen_dd_fb_mm256_load_pd(in_ddi+368); \
        ddi_4 a93 = _igen_dd_fb_mm256_load_pd(in_ddi+372); \
        ddi_4 a94 = _igen_dd_fb_mm256_load_pd(in_ddi+376); \
        ddi_4 a95 = _igen_dd_fb_mm256_load_pd(in_ddi+380); \
        ddi_4 a96 = _igen_dd_fb_mm256_load_pd(in_ddi+384); \
        ddi_4 a97 = _igen_dd_fb_mm256_load_pd(in_ddi+388); \
        ddi_4 a98 = _igen_dd_fb_mm256_load_pd(in_ddi+392); \
        ddi_4 a99 = _igen_dd_fb_mm256_load_pd(in_ddi+396); \
        ddi_4 a100 = _igen_dd_fb_mm256_load_pd(in_ddi+400); \
        ddi_4 a101 = _igen_dd_fb_mm256_load_pd(in_ddi+404); \
        ddi_4 a102 = _igen_dd_fb_mm256_load_pd(in_ddi+408); \
        ddi_4 a103 = _igen_dd_fb_mm256_load_pd(in_ddi+412); \
        ddi_4 a104 = _igen_dd_fb_mm256_load_pd(in_ddi+416); \
        ddi_4 a105 = _igen_dd_fb_mm256_load_pd(in_ddi+420); \
        ddi_4 a106 = _igen_dd_fb_mm256_load_pd(in_ddi+424); \
        ddi_4 a107 = _igen_dd_fb_mm256_load_pd(in_ddi+428); \
        ddi_4 a108 = _igen_dd_fb_mm256_load_pd(in_ddi+432); \
        ddi_4 a109 = _igen_dd_fb_mm256_load_pd(in_ddi+436); \
        ddi_4 a110 = _igen_dd_fb_mm256_load_pd(in_ddi+440); \
        ddi_4 a111 = _igen_dd_fb_mm256_load_pd(in_ddi+444); \
        ddi_4 a112 = _igen_dd_fb_mm256_load_pd(in_ddi+448); \
        ddi_4 a113 = _igen_dd_fb_mm256_load_pd(in_ddi+452); \
        ddi_4 a114 = _igen_dd_fb_mm256_load_pd(in_ddi+456); \
        ddi_4 a115 = _igen_dd_fb_mm256_load_pd(in_ddi+460); \
        ddi_4 a116 = _igen_dd_fb_mm256_load_pd(in_ddi+464); \
        ddi_4 a117 = _igen_dd_fb_mm256_load_pd(in_ddi+468); \
        ddi_4 a118 = _igen_dd_fb_mm256_load_pd(in_ddi+472); \
        ddi_4 a119 = _igen_dd_fb_mm256_load_pd(in_ddi+476); \
        ddi_4 a120 = _igen_dd_fb_mm256_load_pd(in_ddi+480); \
        ddi_4 a121 = _igen_dd_fb_mm256_load_pd(in_ddi+484); \
        ddi_4 a122 = _igen_dd_fb_mm256_load_pd(in_ddi+488); \
        ddi_4 a123 = _igen_dd_fb_mm256_load_pd(in_ddi+492); \
        ddi_4 a124 = _igen_dd_fb_mm256_load_pd(in_ddi+496); \
        ddi_4 a125 = _igen_dd_fb_mm256_load_pd(in_ddi+500); \
        ddi_4 a126 = _igen_dd_fb_mm256_load_pd(in_ddi+504); \
        ddi_4 a127 = _igen_dd_fb_mm256_load_pd(in_ddi+508); \
        ddi_4 a128 = _igen_dd_fb_mm256_load_pd(in_ddi+512); \
        ddi_4 a129 = _igen_dd_fb_mm256_load_pd(in_ddi+516); \
        ddi_4 a130 = _igen_dd_fb_mm256_load_pd(in_ddi+520); \
        ddi_4 a131 = _igen_dd_fb_mm256_load_pd(in_ddi+524); \
        ddi_4 a132 = _igen_dd_fb_mm256_load_pd(in_ddi+528); \
        ddi_4 a133 = _igen_dd_fb_mm256_load_pd(in_ddi+532); \
        ddi_4 a134 = _igen_dd_fb_mm256_load_pd(in_ddi+536); \
        ddi_4 a135 = _igen_dd_fb_mm256_load_pd(in_ddi+540); \
        ddi_4 a136 = _igen_dd_fb_mm256_load_pd(in_ddi+544); \
        ddi_4 a137 = _igen_dd_fb_mm256_load_pd(in_ddi+548); \
        ddi_4 a138 = _igen_dd_fb_mm256_load_pd(in_ddi+552); \
        ddi_4 a139 = _igen_dd_fb_mm256_load_pd(in_ddi+556); \
        ddi_4 a140 = _igen_dd_fb_mm256_load_pd(in_ddi+560); \
        ddi_4 a141 = _igen_dd_fb_mm256_load_pd(in_ddi+564); \
        ddi_4 a142 = _igen_dd_fb_mm256_load_pd(in_ddi+568); \
        ddi_4 a143 = _igen_dd_fb_mm256_load_pd(in_ddi+572); \
        ddi_4 a144 = _igen_dd_fb_mm256_load_pd(in_ddi+576); \
        ddi_4 a145 = _igen_dd_fb_mm256_load_pd(in_ddi+580); \
        ddi_4 a146 = _igen_dd_fb_mm256_load_pd(in_ddi+584); \
        ddi_4 a147 = _igen_dd_fb_mm256_load_pd(in_ddi+588); \
        ddi_4 a148 = _igen_dd_fb_mm256_load_pd(in_ddi+592); \
        ddi_4 a149 = _igen_dd_fb_mm256_load_pd(in_ddi+596); \
        ddi_4 a150 = _igen_dd_fb_mm256_load_pd(in_ddi+600); \
        ddi_4 a151 = _igen_dd_fb_mm256_load_pd(in_ddi+604); \
        ddi_4 a152 = _igen_dd_fb_mm256_load_pd(in_ddi+608); \
        ddi_4 a153 = _igen_dd_fb_mm256_load_pd(in_ddi+612); \
        ddi_4 a154 = _igen_dd_fb_mm256_load_pd(in_ddi+616); \
        ddi_4 a155 = _igen_dd_fb_mm256_load_pd(in_ddi+620); \
        ddi_4 a156 = _igen_dd_fb_mm256_load_pd(in_ddi+624); \
        ddi_4 a157 = _igen_dd_fb_mm256_load_pd(in_ddi+628); \
        ddi_4 a158 = _igen_dd_fb_mm256_load_pd(in_ddi+632); \
        ddi_4 a159 = _igen_dd_fb_mm256_load_pd(in_ddi+636); \
        ddi_4 a160 = _igen_dd_fb_mm256_load_pd(in_ddi+640); \
        ddi_4 a161 = _igen_dd_fb_mm256_load_pd(in_ddi+644); \
        ddi_4 a162 = _igen_dd_fb_mm256_load_pd(in_ddi+648); \
        ddi_4 a163 = _igen_dd_fb_mm256_load_pd(in_ddi+652); \
        ddi_4 a164 = _igen_dd_fb_mm256_load_pd(in_ddi+656); \
        ddi_4 a165 = _igen_dd_fb_mm256_load_pd(in_ddi+660); \
        ddi_4 a166 = _igen_dd_fb_mm256_load_pd(in_ddi+664); \
        ddi_4 a167 = _igen_dd_fb_mm256_load_pd(in_ddi+668); \
        ddi_4 a168 = _igen_dd_fb_mm256_load_pd(in_ddi+672); \
        ddi_4 a169 = _igen_dd_fb_mm256_load_pd(in_ddi+676); \
        ddi_4 a170 = _igen_dd_fb_mm256_load_pd(in_ddi+680); \
        ddi_4 a171 = _igen_dd_fb_mm256_load_pd(in_ddi+684); \
        ddi_4 a172 = _igen_dd_fb_mm256_load_pd(in_ddi+688); \
        ddi_4 a173 = _igen_dd_fb_mm256_load_pd(in_ddi+692); \
        ddi_4 a174 = _igen_dd_fb_mm256_load_pd(in_ddi+696); \
        ddi_4 a175 = _igen_dd_fb_mm256_load_pd(in_ddi+700); \
        ddi_4 a176 = _igen_dd_fb_mm256_load_pd(in_ddi+704); \
        ddi_4 a177 = _igen_dd_fb_mm256_load_pd(in_ddi+708); \
        ddi_4 a178 = _igen_dd_fb_mm256_load_pd(in_ddi+712); \
        ddi_4 a179 = _igen_dd_fb_mm256_load_pd(in_ddi+716); \
        ddi_4 a180 = _igen_dd_fb_mm256_load_pd(in_ddi+720); \
        ddi_4 a181 = _igen_dd_fb_mm256_load_pd(in_ddi+724); \
        ddi_4 a182 = _igen_dd_fb_mm256_load_pd(in_ddi+728); \
        ddi_4 a183 = _igen_dd_fb_mm256_load_pd(in_ddi+732); \
        ddi_4 a184 = _igen_dd_fb_mm256_load_pd(in_ddi+736); \
        ddi_4 a185 = _igen_dd_fb_mm256_load_pd(in_ddi+740); \
        ddi_4 a186 = _igen_dd_fb_mm256_load_pd(in_ddi+744); \
        ddi_4 a187 = _igen_dd_fb_mm256_load_pd(in_ddi+748); \
        ddi_4 a188 = _igen_dd_fb_mm256_load_pd(in_ddi+752); \
        ddi_4 a189 = _igen_dd_fb_mm256_load_pd(in_ddi+756); \
        ddi_4 a190 = _igen_dd_fb_mm256_load_pd(in_ddi+760); \
        ddi_4 a191 = _igen_dd_fb_mm256_load_pd(in_ddi+764); \
        ddi_4 a192 = _igen_dd_fb_mm256_load_pd(in_ddi+768); \
        ddi_4 a193 = _igen_dd_fb_mm256_load_pd(in_ddi+772); \
        ddi_4 a194 = _igen_dd_fb_mm256_load_pd(in_ddi+776); \
        ddi_4 a195 = _igen_dd_fb_mm256_load_pd(in_ddi+780); \
        ddi_4 a196 = _igen_dd_fb_mm256_load_pd(in_ddi+784); \
        ddi_4 a197 = _igen_dd_fb_mm256_load_pd(in_ddi+788); \
        ddi_4 a198 = _igen_dd_fb_mm256_load_pd(in_ddi+792); \
        ddi_4 a199 = _igen_dd_fb_mm256_load_pd(in_ddi+796); \
        ddi_4 a200 = _igen_dd_fb_mm256_load_pd(in_ddi+800); \
        ddi_4 a201 = _igen_dd_fb_mm256_load_pd(in_ddi+804); \
        ddi_4 a202 = _igen_dd_fb_mm256_load_pd(in_ddi+808); \
        ddi_4 a203 = _igen_dd_fb_mm256_load_pd(in_ddi+812); \
        ddi_4 a204 = _igen_dd_fb_mm256_load_pd(in_ddi+816); \
        ddi_4 a205 = _igen_dd_fb_mm256_load_pd(in_ddi+820); \
        ddi_4 a206 = _igen_dd_fb_mm256_load_pd(in_ddi+824); \
        ddi_4 a207 = _igen_dd_fb_mm256_load_pd(in_ddi+828); \
        ddi_4 a208 = _igen_dd_fb_mm256_load_pd(in_ddi+832); \
        ddi_4 a209 = _igen_dd_fb_mm256_load_pd(in_ddi+836); \
        ddi_4 a210 = _igen_dd_fb_mm256_load_pd(in_ddi+840); \
        ddi_4 a211 = _igen_dd_fb_mm256_load_pd(in_ddi+844); \
        ddi_4 a212 = _igen_dd_fb_mm256_load_pd(in_ddi+848); \
        ddi_4 a213 = _igen_dd_fb_mm256_load_pd(in_ddi+852); \
        ddi_4 a214 = _igen_dd_fb_mm256_load_pd(in_ddi+856); \
        ddi_4 a215 = _igen_dd_fb_mm256_load_pd(in_ddi+860); \
        ddi_4 a216 = _igen_dd_fb_mm256_load_pd(in_ddi+864); \
        ddi_4 a217 = _igen_dd_fb_mm256_load_pd(in_ddi+868); \
        ddi_4 a218 = _igen_dd_fb_mm256_load_pd(in_ddi+872); \
        ddi_4 a219 = _igen_dd_fb_mm256_load_pd(in_ddi+876); \
        ddi_4 a220 = _igen_dd_fb_mm256_load_pd(in_ddi+880); \
        ddi_4 a221 = _igen_dd_fb_mm256_load_pd(in_ddi+884); \
        ddi_4 a222 = _igen_dd_fb_mm256_load_pd(in_ddi+888); \
        ddi_4 a223 = _igen_dd_fb_mm256_load_pd(in_ddi+892); \
        ddi_4 a224 = _igen_dd_fb_mm256_load_pd(in_ddi+896); \
        ddi_4 a225 = _igen_dd_fb_mm256_load_pd(in_ddi+900); \
        ddi_4 a226 = _igen_dd_fb_mm256_load_pd(in_ddi+904); \
        ddi_4 a227 = _igen_dd_fb_mm256_load_pd(in_ddi+908); \
        ddi_4 a228 = _igen_dd_fb_mm256_load_pd(in_ddi+912); \
        ddi_4 a229 = _igen_dd_fb_mm256_load_pd(in_ddi+916); \
        ddi_4 a230 = _igen_dd_fb_mm256_load_pd(in_ddi+920); \
        ddi_4 a231 = _igen_dd_fb_mm256_load_pd(in_ddi+924); \
        ddi_4 a232 = _igen_dd_fb_mm256_load_pd(in_ddi+928); \
        ddi_4 a233 = _igen_dd_fb_mm256_load_pd(in_ddi+932); \
        ddi_4 a234 = _igen_dd_fb_mm256_load_pd(in_ddi+936); \
        ddi_4 a235 = _igen_dd_fb_mm256_load_pd(in_ddi+940); \
        ddi_4 a236 = _igen_dd_fb_mm256_load_pd(in_ddi+944); \
        ddi_4 a237 = _igen_dd_fb_mm256_load_pd(in_ddi+948); \
        ddi_4 a238 = _igen_dd_fb_mm256_load_pd(in_ddi+952); \
        ddi_4 a239 = _igen_dd_fb_mm256_load_pd(in_ddi+956); \
        ddi_4 a240 = _igen_dd_fb_mm256_load_pd(in_ddi+960); \
        ddi_4 a241 = _igen_dd_fb_mm256_load_pd(in_ddi+964); \
        ddi_4 a242 = _igen_dd_fb_mm256_load_pd(in_ddi+968); \
        ddi_4 a243 = _igen_dd_fb_mm256_load_pd(in_ddi+972); \
        ddi_4 a244 = _igen_dd_fb_mm256_load_pd(in_ddi+976); \
        ddi_4 a245 = _igen_dd_fb_mm256_load_pd(in_ddi+980); \
        ddi_4 a246 = _igen_dd_fb_mm256_load_pd(in_ddi+984); \
        ddi_4 a247 = _igen_dd_fb_mm256_load_pd(in_ddi+988); \
        ddi_4 a248 = _igen_dd_fb_mm256_load_pd(in_ddi+992); \
        ddi_4 a249 = _igen_dd_fb_mm256_load_pd(in_ddi+996); \
        ddi_4 a250 = _igen_dd_fb_mm256_load_pd(in_ddi+1000); \
        ddi_4 a251 = _igen_dd_fb_mm256_load_pd(in_ddi+1004); \
        ddi_4 a252 = _igen_dd_fb_mm256_load_pd(in_ddi+1008); \
        ddi_4 a253 = _igen_dd_fb_mm256_load_pd(in_ddi+1012); \
        ddi_4 a254 = _igen_dd_fb_mm256_load_pd(in_ddi+1016); \
        ddi_4 a255 = _igen_dd_fb_mm256_load_pd(in_ddi+1020); \
                                                             \
        ddi_2 b0 = _igen_dd_fb_mm_load_pd(in_ddi+1024); \
        ddi_2 b1 = _igen_dd_fb_mm_load_pd(in_ddi+1026); \
        ddi_2 b2 = _igen_dd_fb_mm_load_pd(in_ddi+1028); \
        ddi_2 b3 = _igen_dd_fb_mm_load_pd(in_ddi+1030); \
        ddi_2 b4 = _igen_dd_fb_mm_load_pd(in_ddi+1032); \
        ddi_2 b5 = _igen_dd_fb_mm_load_pd(in_ddi+1034); \
        ddi_2 b6 = _igen_dd_fb_mm_load_pd(in_ddi+1036); \
        ddi_2 b7 = _igen_dd_fb_mm_load_pd(in_ddi+1038); \
        ddi_2 b8 = _igen_dd_fb_mm_load_pd(in_ddi+1040); \
        ddi_2 b9 = _igen_dd_fb_mm_load_pd(in_ddi+1042); \
        ddi_2 b10 = _igen_dd_fb_mm_load_pd(in_ddi+1044); \
        ddi_2 b11 = _igen_dd_fb_mm_load_pd(in_ddi+1046); \
        ddi_2 b12 = _igen_dd_fb_mm_load_pd(in_ddi+1048); \
        ddi_2 b13 = _igen_dd_fb_mm_load_pd(in_ddi+1050); \
        ddi_2 b14 = _igen_dd_fb_mm_load_pd(in_ddi+1052); \
        ddi_2 b15 = _igen_dd_fb_mm_load_pd(in_ddi+1054); \
        ddi_2 b16 = _igen_dd_fb_mm_load_pd(in_ddi+1056); \
        ddi_2 b17 = _igen_dd_fb_mm_load_pd(in_ddi+1058); \
        ddi_2 b18 = _igen_dd_fb_mm_load_pd(in_ddi+1060); \
        ddi_2 b19 = _igen_dd_fb_mm_load_pd(in_ddi+1062); \
        ddi_2 b20 = _igen_dd_fb_mm_load_pd(in_ddi+1064); \
        ddi_2 b21 = _igen_dd_fb_mm_load_pd(in_ddi+1066); \
        ddi_2 b22 = _igen_dd_fb_mm_load_pd(in_ddi+1068); \
        ddi_2 b23 = _igen_dd_fb_mm_load_pd(in_ddi+1070); \
        ddi_2 b24 = _igen_dd_fb_mm_load_pd(in_ddi+1072); \
        ddi_2 b25 = _igen_dd_fb_mm_load_pd(in_ddi+1074); \
        ddi_2 b26 = _igen_dd_fb_mm_load_pd(in_ddi+1076); \
        ddi_2 b27 = _igen_dd_fb_mm_load_pd(in_ddi+1078); \
        ddi_2 b28 = _igen_dd_fb_mm_load_pd(in_ddi+1080); \
        ddi_2 b29 = _igen_dd_fb_mm_load_pd(in_ddi+1082); \
        ddi_2 b30 = _igen_dd_fb_mm_load_pd(in_ddi+1084); \
        ddi_2 b31 = _igen_dd_fb_mm_load_pd(in_ddi+1086); \
        ddi_2 b32 = _igen_dd_fb_mm_load_pd(in_ddi+1088); \
        ddi_2 b33 = _igen_dd_fb_mm_load_pd(in_ddi+1090); \
        ddi_2 b34 = _igen_dd_fb_mm_load_pd(in_ddi+1092); \
        ddi_2 b35 = _igen_dd_fb_mm_load_pd(in_ddi+1094); \
        ddi_2 b36 = _igen_dd_fb_mm_load_pd(in_ddi+1096); \
        ddi_2 b37 = _igen_dd_fb_mm_load_pd(in_ddi+1098); \
        ddi_2 b38 = _igen_dd_fb_mm_load_pd(in_ddi+1100); \
        ddi_2 b39 = _igen_dd_fb_mm_load_pd(in_ddi+1102); \
        ddi_2 b40 = _igen_dd_fb_mm_load_pd(in_ddi+1104); \
        ddi_2 b41 = _igen_dd_fb_mm_load_pd(in_ddi+1106); \
        ddi_2 b42 = _igen_dd_fb_mm_load_pd(in_ddi+1108); \
        ddi_2 b43 = _igen_dd_fb_mm_load_pd(in_ddi+1110); \
        ddi_2 b44 = _igen_dd_fb_mm_load_pd(in_ddi+1112); \
        ddi_2 b45 = _igen_dd_fb_mm_load_pd(in_ddi+1114); \
        ddi_2 b46 = _igen_dd_fb_mm_load_pd(in_ddi+1116); \
        ddi_2 b47 = _igen_dd_fb_mm_load_pd(in_ddi+1118); \
        ddi_2 b48 = _igen_dd_fb_mm_load_pd(in_ddi+1120); \
        ddi_2 b49 = _igen_dd_fb_mm_load_pd(in_ddi+1122); \
        ddi_2 b50 = _igen_dd_fb_mm_load_pd(in_ddi+1124); \
        ddi_2 b51 = _igen_dd_fb_mm_load_pd(in_ddi+1126); \
        ddi_2 b52 = _igen_dd_fb_mm_load_pd(in_ddi+1128); \
        ddi_2 b53 = _igen_dd_fb_mm_load_pd(in_ddi+1130); \
        ddi_2 b54 = _igen_dd_fb_mm_load_pd(in_ddi+1132); \
        ddi_2 b55 = _igen_dd_fb_mm_load_pd(in_ddi+1134); \
        ddi_2 b56 = _igen_dd_fb_mm_load_pd(in_ddi+1136); \
        ddi_2 b57 = _igen_dd_fb_mm_load_pd(in_ddi+1138); \
        ddi_2 b58 = _igen_dd_fb_mm_load_pd(in_ddi+1140); \
        ddi_2 b59 = _igen_dd_fb_mm_load_pd(in_ddi+1142); \
        ddi_2 b60 = _igen_dd_fb_mm_load_pd(in_ddi+1144); \
        ddi_2 b61 = _igen_dd_fb_mm_load_pd(in_ddi+1146); \
        ddi_2 b62 = _igen_dd_fb_mm_load_pd(in_ddi+1148); \
        ddi_2 b63 = _igen_dd_fb_mm_load_pd(in_ddi+1150); \
        ddi_2 b64 = _igen_dd_fb_mm_load_pd(in_ddi+1152); \
        ddi_2 b65 = _igen_dd_fb_mm_load_pd(in_ddi+1154); \
        ddi_2 b66 = _igen_dd_fb_mm_load_pd(in_ddi+1156); \
        ddi_2 b67 = _igen_dd_fb_mm_load_pd(in_ddi+1158); \
        ddi_2 b68 = _igen_dd_fb_mm_load_pd(in_ddi+1160); \
        ddi_2 b69 = _igen_dd_fb_mm_load_pd(in_ddi+1162); \
        ddi_2 b70 = _igen_dd_fb_mm_load_pd(in_ddi+1164); \
        ddi_2 b71 = _igen_dd_fb_mm_load_pd(in_ddi+1166); \
        ddi_2 b72 = _igen_dd_fb_mm_load_pd(in_ddi+1168); \
        ddi_2 b73 = _igen_dd_fb_mm_load_pd(in_ddi+1170); \
        ddi_2 b74 = _igen_dd_fb_mm_load_pd(in_ddi+1172); \
        ddi_2 b75 = _igen_dd_fb_mm_load_pd(in_ddi+1174); \
        ddi_2 b76 = _igen_dd_fb_mm_load_pd(in_ddi+1176); \
        ddi_2 b77 = _igen_dd_fb_mm_load_pd(in_ddi+1178); \
        ddi_2 b78 = _igen_dd_fb_mm_load_pd(in_ddi+1180); \
        ddi_2 b79 = _igen_dd_fb_mm_load_pd(in_ddi+1182); \
        ddi_2 b80 = _igen_dd_fb_mm_load_pd(in_ddi+1184); \
        ddi_2 b81 = _igen_dd_fb_mm_load_pd(in_ddi+1186); \
        ddi_2 b82 = _igen_dd_fb_mm_load_pd(in_ddi+1188); \
        ddi_2 b83 = _igen_dd_fb_mm_load_pd(in_ddi+1190); \
        ddi_2 b84 = _igen_dd_fb_mm_load_pd(in_ddi+1192); \
        ddi_2 b85 = _igen_dd_fb_mm_load_pd(in_ddi+1194); \
        ddi_2 b86 = _igen_dd_fb_mm_load_pd(in_ddi+1196); \
        ddi_2 b87 = _igen_dd_fb_mm_load_pd(in_ddi+1198); \
        ddi_2 b88 = _igen_dd_fb_mm_load_pd(in_ddi+1200); \
        ddi_2 b89 = _igen_dd_fb_mm_load_pd(in_ddi+1202); \
        ddi_2 b90 = _igen_dd_fb_mm_load_pd(in_ddi+1204); \
        ddi_2 b91 = _igen_dd_fb_mm_load_pd(in_ddi+1206); \
        ddi_2 b92 = _igen_dd_fb_mm_load_pd(in_ddi+1208); \
        ddi_2 b93 = _igen_dd_fb_mm_load_pd(in_ddi+1210); \
        ddi_2 b94 = _igen_dd_fb_mm_load_pd(in_ddi+1212); \
        ddi_2 b95 = _igen_dd_fb_mm_load_pd(in_ddi+1214); \
        ddi_2 b96 = _igen_dd_fb_mm_load_pd(in_ddi+1216); \
        ddi_2 b97 = _igen_dd_fb_mm_load_pd(in_ddi+1218); \
        ddi_2 b98 = _igen_dd_fb_mm_load_pd(in_ddi+1220); \
        ddi_2 b99 = _igen_dd_fb_mm_load_pd(in_ddi+1222); \
        ddi_2 b100 = _igen_dd_fb_mm_load_pd(in_ddi+1224); \
        ddi_2 b101 = _igen_dd_fb_mm_load_pd(in_ddi+1226); \
        ddi_2 b102 = _igen_dd_fb_mm_load_pd(in_ddi+1228); \
        ddi_2 b103 = _igen_dd_fb_mm_load_pd(in_ddi+1230); \
        ddi_2 b104 = _igen_dd_fb_mm_load_pd(in_ddi+1232); \
        ddi_2 b105 = _igen_dd_fb_mm_load_pd(in_ddi+1234); \
        ddi_2 b106 = _igen_dd_fb_mm_load_pd(in_ddi+1236); \
        ddi_2 b107 = _igen_dd_fb_mm_load_pd(in_ddi+1238); \
        ddi_2 b108 = _igen_dd_fb_mm_load_pd(in_ddi+1240); \
        ddi_2 b109 = _igen_dd_fb_mm_load_pd(in_ddi+1242); \
        ddi_2 b110 = _igen_dd_fb_mm_load_pd(in_ddi+1244); \
        ddi_2 b111 = _igen_dd_fb_mm_load_pd(in_ddi+1246); \
        ddi_2 b112 = _igen_dd_fb_mm_load_pd(in_ddi+1248); \
        ddi_2 b113 = _igen_dd_fb_mm_load_pd(in_ddi+1250); \
        ddi_2 b114 = _igen_dd_fb_mm_load_pd(in_ddi+1252); \
        ddi_2 b115 = _igen_dd_fb_mm_load_pd(in_ddi+1254); \
        ddi_2 b116 = _igen_dd_fb_mm_load_pd(in_ddi+1256); \
        ddi_2 b117 = _igen_dd_fb_mm_load_pd(in_ddi+1258); \
        ddi_2 b118 = _igen_dd_fb_mm_load_pd(in_ddi+1260); \
        ddi_2 b119 = _igen_dd_fb_mm_load_pd(in_ddi+1262); \
        ddi_2 b120 = _igen_dd_fb_mm_load_pd(in_ddi+1264); \
        ddi_2 b121 = _igen_dd_fb_mm_load_pd(in_ddi+1266); \
        ddi_2 b122 = _igen_dd_fb_mm_load_pd(in_ddi+1268); \
        ddi_2 b123 = _igen_dd_fb_mm_load_pd(in_ddi+1270); \
        ddi_2 b124 = _igen_dd_fb_mm_load_pd(in_ddi+1272); \
        ddi_2 b125 = _igen_dd_fb_mm_load_pd(in_ddi+1274); \
        ddi_2 b126 = _igen_dd_fb_mm_load_pd(in_ddi+1276); \
        ddi_2 b127 = _igen_dd_fb_mm_load_pd(in_ddi+1278); \
        ddi_2 b128 = _igen_dd_fb_mm_load_pd(in_ddi+1280); \
        ddi_2 b129 = _igen_dd_fb_mm_load_pd(in_ddi+1282); \
        ddi_2 b130 = _igen_dd_fb_mm_load_pd(in_ddi+1284); \
        ddi_2 b131 = _igen_dd_fb_mm_load_pd(in_ddi+1286); \
        ddi_2 b132 = _igen_dd_fb_mm_load_pd(in_ddi+1288); \
        ddi_2 b133 = _igen_dd_fb_mm_load_pd(in_ddi+1290); \
        ddi_2 b134 = _igen_dd_fb_mm_load_pd(in_ddi+1292); \
        ddi_2 b135 = _igen_dd_fb_mm_load_pd(in_ddi+1294); \
        ddi_2 b136 = _igen_dd_fb_mm_load_pd(in_ddi+1296); \
        ddi_2 b137 = _igen_dd_fb_mm_load_pd(in_ddi+1298); \
        ddi_2 b138 = _igen_dd_fb_mm_load_pd(in_ddi+1300); \
        ddi_2 b139 = _igen_dd_fb_mm_load_pd(in_ddi+1302); \
        ddi_2 b140 = _igen_dd_fb_mm_load_pd(in_ddi+1304); \
        ddi_2 b141 = _igen_dd_fb_mm_load_pd(in_ddi+1306); \
        ddi_2 b142 = _igen_dd_fb_mm_load_pd(in_ddi+1308); \
        ddi_2 b143 = _igen_dd_fb_mm_load_pd(in_ddi+1310); \
        ddi_2 b144 = _igen_dd_fb_mm_load_pd(in_ddi+1312); \
        ddi_2 b145 = _igen_dd_fb_mm_load_pd(in_ddi+1314); \
        ddi_2 b146 = _igen_dd_fb_mm_load_pd(in_ddi+1316); \
        ddi_2 b147 = _igen_dd_fb_mm_load_pd(in_ddi+1318); \
        ddi_2 b148 = _igen_dd_fb_mm_load_pd(in_ddi+1320); \
        ddi_2 b149 = _igen_dd_fb_mm_load_pd(in_ddi+1322); \
        ddi_2 b150 = _igen_dd_fb_mm_load_pd(in_ddi+1324); \
        ddi_2 b151 = _igen_dd_fb_mm_load_pd(in_ddi+1326); \
        ddi_2 b152 = _igen_dd_fb_mm_load_pd(in_ddi+1328); \
        ddi_2 b153 = _igen_dd_fb_mm_load_pd(in_ddi+1330); \
        ddi_2 b154 = _igen_dd_fb_mm_load_pd(in_ddi+1332); \
        ddi_2 b155 = _igen_dd_fb_mm_load_pd(in_ddi+1334); \
        ddi_2 b156 = _igen_dd_fb_mm_load_pd(in_ddi+1336); \
        ddi_2 b157 = _igen_dd_fb_mm_load_pd(in_ddi+1338); \
        ddi_2 b158 = _igen_dd_fb_mm_load_pd(in_ddi+1340); \
        ddi_2 b159 = _igen_dd_fb_mm_load_pd(in_ddi+1342); \
        ddi_2 b160 = _igen_dd_fb_mm_load_pd(in_ddi+1344); \
        ddi_2 b161 = _igen_dd_fb_mm_load_pd(in_ddi+1346); \
        ddi_2 b162 = _igen_dd_fb_mm_load_pd(in_ddi+1348); \
        ddi_2 b163 = _igen_dd_fb_mm_load_pd(in_ddi+1350); \
        ddi_2 b164 = _igen_dd_fb_mm_load_pd(in_ddi+1352); \
        ddi_2 b165 = _igen_dd_fb_mm_load_pd(in_ddi+1354); \
        ddi_2 b166 = _igen_dd_fb_mm_load_pd(in_ddi+1356); \
        ddi_2 b167 = _igen_dd_fb_mm_load_pd(in_ddi+1358); \
        ddi_2 b168 = _igen_dd_fb_mm_load_pd(in_ddi+1360); \
        ddi_2 b169 = _igen_dd_fb_mm_load_pd(in_ddi+1362); \
        ddi_2 b170 = _igen_dd_fb_mm_load_pd(in_ddi+1364); \
        ddi_2 b171 = _igen_dd_fb_mm_load_pd(in_ddi+1366); \
        ddi_2 b172 = _igen_dd_fb_mm_load_pd(in_ddi+1368); \
        ddi_2 b173 = _igen_dd_fb_mm_load_pd(in_ddi+1370); \
        ddi_2 b174 = _igen_dd_fb_mm_load_pd(in_ddi+1372); \
        ddi_2 b175 = _igen_dd_fb_mm_load_pd(in_ddi+1374); \
        ddi_2 b176 = _igen_dd_fb_mm_load_pd(in_ddi+1376); \
        ddi_2 b177 = _igen_dd_fb_mm_load_pd(in_ddi+1378); \
        ddi_2 b178 = _igen_dd_fb_mm_load_pd(in_ddi+1380); \
        ddi_2 b179 = _igen_dd_fb_mm_load_pd(in_ddi+1382); \
        ddi_2 b180 = _igen_dd_fb_mm_load_pd(in_ddi+1384); \
        ddi_2 b181 = _igen_dd_fb_mm_load_pd(in_ddi+1386); \
        ddi_2 b182 = _igen_dd_fb_mm_load_pd(in_ddi+1388); \
        ddi_2 b183 = _igen_dd_fb_mm_load_pd(in_ddi+1390); \
        ddi_2 b184 = _igen_dd_fb_mm_load_pd(in_ddi+1392); \
        ddi_2 b185 = _igen_dd_fb_mm_load_pd(in_ddi+1394); \
        ddi_2 b186 = _igen_dd_fb_mm_load_pd(in_ddi+1396); \
        ddi_2 b187 = _igen_dd_fb_mm_load_pd(in_ddi+1398); \
        ddi_2 b188 = _igen_dd_fb_mm_load_pd(in_ddi+1400); \
        ddi_2 b189 = _igen_dd_fb_mm_load_pd(in_ddi+1402); \
        ddi_2 b190 = _igen_dd_fb_mm_load_pd(in_ddi+1404); \
        ddi_2 b191 = _igen_dd_fb_mm_load_pd(in_ddi+1406); \
        ddi_2 b192 = _igen_dd_fb_mm_load_pd(in_ddi+1408); \
        ddi_2 b193 = _igen_dd_fb_mm_load_pd(in_ddi+1410); \
        ddi_2 b194 = _igen_dd_fb_mm_load_pd(in_ddi+1412); \
        ddi_2 b195 = _igen_dd_fb_mm_load_pd(in_ddi+1414); \
        ddi_2 b196 = _igen_dd_fb_mm_load_pd(in_ddi+1416); \
        ddi_2 b197 = _igen_dd_fb_mm_load_pd(in_ddi+1418); \
        ddi_2 b198 = _igen_dd_fb_mm_load_pd(in_ddi+1420); \
        ddi_2 b199 = _igen_dd_fb_mm_load_pd(in_ddi+1422); \
        ddi_2 b200 = _igen_dd_fb_mm_load_pd(in_ddi+1424); \
        ddi_2 b201 = _igen_dd_fb_mm_load_pd(in_ddi+1426); \
        ddi_2 b202 = _igen_dd_fb_mm_load_pd(in_ddi+1428); \
        ddi_2 b203 = _igen_dd_fb_mm_load_pd(in_ddi+1430); \
        ddi_2 b204 = _igen_dd_fb_mm_load_pd(in_ddi+1432); \
        ddi_2 b205 = _igen_dd_fb_mm_load_pd(in_ddi+1434); \
        ddi_2 b206 = _igen_dd_fb_mm_load_pd(in_ddi+1436); \
        ddi_2 b207 = _igen_dd_fb_mm_load_pd(in_ddi+1438); \
        ddi_2 b208 = _igen_dd_fb_mm_load_pd(in_ddi+1440); \
        ddi_2 b209 = _igen_dd_fb_mm_load_pd(in_ddi+1442); \
        ddi_2 b210 = _igen_dd_fb_mm_load_pd(in_ddi+1444); \
        ddi_2 b211 = _igen_dd_fb_mm_load_pd(in_ddi+1446); \
        ddi_2 b212 = _igen_dd_fb_mm_load_pd(in_ddi+1448); \
        ddi_2 b213 = _igen_dd_fb_mm_load_pd(in_ddi+1450); \
        ddi_2 b214 = _igen_dd_fb_mm_load_pd(in_ddi+1452); \
        ddi_2 b215 = _igen_dd_fb_mm_load_pd(in_ddi+1454); \
        ddi_2 b216 = _igen_dd_fb_mm_load_pd(in_ddi+1456); \
        ddi_2 b217 = _igen_dd_fb_mm_load_pd(in_ddi+1458); \
        ddi_2 b218 = _igen_dd_fb_mm_load_pd(in_ddi+1460); \
        ddi_2 b219 = _igen_dd_fb_mm_load_pd(in_ddi+1462); \
        ddi_2 b220 = _igen_dd_fb_mm_load_pd(in_ddi+1464); \
        ddi_2 b221 = _igen_dd_fb_mm_load_pd(in_ddi+1466); \
        ddi_2 b222 = _igen_dd_fb_mm_load_pd(in_ddi+1468); \
        ddi_2 b223 = _igen_dd_fb_mm_load_pd(in_ddi+1470); \
        ddi_2 b224 = _igen_dd_fb_mm_load_pd(in_ddi+1472); \
        ddi_2 b225 = _igen_dd_fb_mm_load_pd(in_ddi+1474); \
        ddi_2 b226 = _igen_dd_fb_mm_load_pd(in_ddi+1476); \
        ddi_2 b227 = _igen_dd_fb_mm_load_pd(in_ddi+1478); \
        ddi_2 b228 = _igen_dd_fb_mm_load_pd(in_ddi+1480); \
        ddi_2 b229 = _igen_dd_fb_mm_load_pd(in_ddi+1482); \
        ddi_2 b230 = _igen_dd_fb_mm_load_pd(in_ddi+1484); \
        ddi_2 b231 = _igen_dd_fb_mm_load_pd(in_ddi+1486); \
        ddi_2 b232 = _igen_dd_fb_mm_load_pd(in_ddi+1488); \
        ddi_2 b233 = _igen_dd_fb_mm_load_pd(in_ddi+1490); \
        ddi_2 b234 = _igen_dd_fb_mm_load_pd(in_ddi+1492); \
        ddi_2 b235 = _igen_dd_fb_mm_load_pd(in_ddi+1494); \
        ddi_2 b236 = _igen_dd_fb_mm_load_pd(in_ddi+1496); \
        ddi_2 b237 = _igen_dd_fb_mm_load_pd(in_ddi+1498); \
        ddi_2 b238 = _igen_dd_fb_mm_load_pd(in_ddi+1500); \
        ddi_2 b239 = _igen_dd_fb_mm_load_pd(in_ddi+1502); \
        ddi_2 b240 = _igen_dd_fb_mm_load_pd(in_ddi+1504); \
        ddi_2 b241 = _igen_dd_fb_mm_load_pd(in_ddi+1506); \
        ddi_2 b242 = _igen_dd_fb_mm_load_pd(in_ddi+1508); \
        ddi_2 b243 = _igen_dd_fb_mm_load_pd(in_ddi+1510); \
        ddi_2 b244 = _igen_dd_fb_mm_load_pd(in_ddi+1512); \
        ddi_2 b245 = _igen_dd_fb_mm_load_pd(in_ddi+1514); \
        ddi_2 b246 = _igen_dd_fb_mm_load_pd(in_ddi+1516); \
        ddi_2 b247 = _igen_dd_fb_mm_load_pd(in_ddi+1518); \
        ddi_2 b248 = _igen_dd_fb_mm_load_pd(in_ddi+1520); \
        ddi_2 b249 = _igen_dd_fb_mm_load_pd(in_ddi+1522); \
        ddi_2 b250 = _igen_dd_fb_mm_load_pd(in_ddi+1524); \
        ddi_2 b251 = _igen_dd_fb_mm_load_pd(in_ddi+1526); \
        ddi_2 b252 = _igen_dd_fb_mm_load_pd(in_ddi+1528); \
        ddi_2 b253 = _igen_dd_fb_mm_load_pd(in_ddi+1530); \
        ddi_2 b254 = _igen_dd_fb_mm_load_pd(in_ddi+1532); \
        ddi_2 b255 = _igen_dd_fb_mm_load_pd(in_ddi+1534); \
                                                       \
        ddi_4 res0 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a0, b0, 0); \
        ddi_4 res1 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a1, b1, 1); \
        ddi_4 res2 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a2, b2, 2); \
        ddi_4 res3 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a3, b3, 3); \
        ddi_4 res4 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a4, b4, 4); \
        ddi_4 res5 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a5, b5, 5); \
        ddi_4 res6 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a6, b6, 6); \
        ddi_4 res7 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a7, b7, 7); \
        ddi_4 res8 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a8, b8, 8); \
        ddi_4 res9 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a9, b9, 9); \
        ddi_4 res10 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a10, b10, 10); \
        ddi_4 res11 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a11, b11, 11); \
        ddi_4 res12 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a12, b12, 12); \
        ddi_4 res13 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a13, b13, 13); \
        ddi_4 res14 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a14, b14, 14); \
        ddi_4 res15 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a15, b15, 15); \
        ddi_4 res16 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a16, b16, 16); \
        ddi_4 res17 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a17, b17, 17); \
        ddi_4 res18 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a18, b18, 18); \
        ddi_4 res19 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a19, b19, 19); \
        ddi_4 res20 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a20, b20, 20); \
        ddi_4 res21 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a21, b21, 21); \
        ddi_4 res22 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a22, b22, 22); \
        ddi_4 res23 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a23, b23, 23); \
        ddi_4 res24 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a24, b24, 24); \
        ddi_4 res25 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a25, b25, 25); \
        ddi_4 res26 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a26, b26, 26); \
        ddi_4 res27 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a27, b27, 27); \
        ddi_4 res28 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a28, b28, 28); \
        ddi_4 res29 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a29, b29, 29); \
        ddi_4 res30 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a30, b30, 30); \
        ddi_4 res31 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a31, b31, 31); \
        ddi_4 res32 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a32, b32, 32); \
        ddi_4 res33 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a33, b33, 33); \
        ddi_4 res34 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a34, b34, 34); \
        ddi_4 res35 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a35, b35, 35); \
        ddi_4 res36 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a36, b36, 36); \
        ddi_4 res37 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a37, b37, 37); \
        ddi_4 res38 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a38, b38, 38); \
        ddi_4 res39 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a39, b39, 39); \
        ddi_4 res40 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a40, b40, 40); \
        ddi_4 res41 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a41, b41, 41); \
        ddi_4 res42 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a42, b42, 42); \
        ddi_4 res43 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a43, b43, 43); \
        ddi_4 res44 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a44, b44, 44); \
        ddi_4 res45 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a45, b45, 45); \
        ddi_4 res46 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a46, b46, 46); \
        ddi_4 res47 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a47, b47, 47); \
        ddi_4 res48 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a48, b48, 48); \
        ddi_4 res49 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a49, b49, 49); \
        ddi_4 res50 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a50, b50, 50); \
        ddi_4 res51 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a51, b51, 51); \
        ddi_4 res52 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a52, b52, 52); \
        ddi_4 res53 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a53, b53, 53); \
        ddi_4 res54 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a54, b54, 54); \
        ddi_4 res55 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a55, b55, 55); \
        ddi_4 res56 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a56, b56, 56); \
        ddi_4 res57 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a57, b57, 57); \
        ddi_4 res58 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a58, b58, 58); \
        ddi_4 res59 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a59, b59, 59); \
        ddi_4 res60 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a60, b60, 60); \
        ddi_4 res61 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a61, b61, 61); \
        ddi_4 res62 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a62, b62, 62); \
        ddi_4 res63 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a63, b63, 63); \
        ddi_4 res64 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a64, b64, 64); \
        ddi_4 res65 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a65, b65, 65); \
        ddi_4 res66 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a66, b66, 66); \
        ddi_4 res67 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a67, b67, 67); \
        ddi_4 res68 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a68, b68, 68); \
        ddi_4 res69 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a69, b69, 69); \
        ddi_4 res70 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a70, b70, 70); \
        ddi_4 res71 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a71, b71, 71); \
        ddi_4 res72 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a72, b72, 72); \
        ddi_4 res73 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a73, b73, 73); \
        ddi_4 res74 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a74, b74, 74); \
        ddi_4 res75 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a75, b75, 75); \
        ddi_4 res76 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a76, b76, 76); \
        ddi_4 res77 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a77, b77, 77); \
        ddi_4 res78 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a78, b78, 78); \
        ddi_4 res79 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a79, b79, 79); \
        ddi_4 res80 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a80, b80, 80); \
        ddi_4 res81 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a81, b81, 81); \
        ddi_4 res82 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a82, b82, 82); \
        ddi_4 res83 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a83, b83, 83); \
        ddi_4 res84 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a84, b84, 84); \
        ddi_4 res85 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a85, b85, 85); \
        ddi_4 res86 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a86, b86, 86); \
        ddi_4 res87 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a87, b87, 87); \
        ddi_4 res88 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a88, b88, 88); \
        ddi_4 res89 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a89, b89, 89); \
        ddi_4 res90 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a90, b90, 90); \
        ddi_4 res91 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a91, b91, 91); \
        ddi_4 res92 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a92, b92, 92); \
        ddi_4 res93 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a93, b93, 93); \
        ddi_4 res94 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a94, b94, 94); \
        ddi_4 res95 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a95, b95, 95); \
        ddi_4 res96 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a96, b96, 96); \
        ddi_4 res97 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a97, b97, 97); \
        ddi_4 res98 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a98, b98, 98); \
        ddi_4 res99 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a99, b99, 99); \
        ddi_4 res100 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a100, b100, 100); \
        ddi_4 res101 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a101, b101, 101); \
        ddi_4 res102 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a102, b102, 102); \
        ddi_4 res103 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a103, b103, 103); \
        ddi_4 res104 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a104, b104, 104); \
        ddi_4 res105 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a105, b105, 105); \
        ddi_4 res106 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a106, b106, 106); \
        ddi_4 res107 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a107, b107, 107); \
        ddi_4 res108 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a108, b108, 108); \
        ddi_4 res109 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a109, b109, 109); \
        ddi_4 res110 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a110, b110, 110); \
        ddi_4 res111 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a111, b111, 111); \
        ddi_4 res112 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a112, b112, 112); \
        ddi_4 res113 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a113, b113, 113); \
        ddi_4 res114 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a114, b114, 114); \
        ddi_4 res115 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a115, b115, 115); \
        ddi_4 res116 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a116, b116, 116); \
        ddi_4 res117 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a117, b117, 117); \
        ddi_4 res118 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a118, b118, 118); \
        ddi_4 res119 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a119, b119, 119); \
        ddi_4 res120 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a120, b120, 120); \
        ddi_4 res121 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a121, b121, 121); \
        ddi_4 res122 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a122, b122, 122); \
        ddi_4 res123 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a123, b123, 123); \
        ddi_4 res124 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a124, b124, 124); \
        ddi_4 res125 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a125, b125, 125); \
        ddi_4 res126 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a126, b126, 126); \
        ddi_4 res127 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a127, b127, 127); \
        ddi_4 res128 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a128, b128, 128); \
        ddi_4 res129 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a129, b129, 129); \
        ddi_4 res130 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a130, b130, 130); \
        ddi_4 res131 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a131, b131, 131); \
        ddi_4 res132 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a132, b132, 132); \
        ddi_4 res133 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a133, b133, 133); \
        ddi_4 res134 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a134, b134, 134); \
        ddi_4 res135 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a135, b135, 135); \
        ddi_4 res136 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a136, b136, 136); \
        ddi_4 res137 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a137, b137, 137); \
        ddi_4 res138 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a138, b138, 138); \
        ddi_4 res139 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a139, b139, 139); \
        ddi_4 res140 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a140, b140, 140); \
        ddi_4 res141 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a141, b141, 141); \
        ddi_4 res142 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a142, b142, 142); \
        ddi_4 res143 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a143, b143, 143); \
        ddi_4 res144 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a144, b144, 144); \
        ddi_4 res145 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a145, b145, 145); \
        ddi_4 res146 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a146, b146, 146); \
        ddi_4 res147 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a147, b147, 147); \
        ddi_4 res148 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a148, b148, 148); \
        ddi_4 res149 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a149, b149, 149); \
        ddi_4 res150 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a150, b150, 150); \
        ddi_4 res151 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a151, b151, 151); \
        ddi_4 res152 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a152, b152, 152); \
        ddi_4 res153 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a153, b153, 153); \
        ddi_4 res154 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a154, b154, 154); \
        ddi_4 res155 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a155, b155, 155); \
        ddi_4 res156 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a156, b156, 156); \
        ddi_4 res157 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a157, b157, 157); \
        ddi_4 res158 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a158, b158, 158); \
        ddi_4 res159 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a159, b159, 159); \
        ddi_4 res160 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a160, b160, 160); \
        ddi_4 res161 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a161, b161, 161); \
        ddi_4 res162 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a162, b162, 162); \
        ddi_4 res163 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a163, b163, 163); \
        ddi_4 res164 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a164, b164, 164); \
        ddi_4 res165 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a165, b165, 165); \
        ddi_4 res166 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a166, b166, 166); \
        ddi_4 res167 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a167, b167, 167); \
        ddi_4 res168 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a168, b168, 168); \
        ddi_4 res169 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a169, b169, 169); \
        ddi_4 res170 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a170, b170, 170); \
        ddi_4 res171 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a171, b171, 171); \
        ddi_4 res172 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a172, b172, 172); \
        ddi_4 res173 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a173, b173, 173); \
        ddi_4 res174 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a174, b174, 174); \
        ddi_4 res175 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a175, b175, 175); \
        ddi_4 res176 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a176, b176, 176); \
        ddi_4 res177 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a177, b177, 177); \
        ddi_4 res178 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a178, b178, 178); \
        ddi_4 res179 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a179, b179, 179); \
        ddi_4 res180 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a180, b180, 180); \
        ddi_4 res181 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a181, b181, 181); \
        ddi_4 res182 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a182, b182, 182); \
        ddi_4 res183 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a183, b183, 183); \
        ddi_4 res184 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a184, b184, 184); \
        ddi_4 res185 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a185, b185, 185); \
        ddi_4 res186 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a186, b186, 186); \
        ddi_4 res187 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a187, b187, 187); \
        ddi_4 res188 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a188, b188, 188); \
        ddi_4 res189 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a189, b189, 189); \
        ddi_4 res190 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a190, b190, 190); \
        ddi_4 res191 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a191, b191, 191); \
        ddi_4 res192 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a192, b192, 192); \
        ddi_4 res193 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a193, b193, 193); \
        ddi_4 res194 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a194, b194, 194); \
        ddi_4 res195 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a195, b195, 195); \
        ddi_4 res196 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a196, b196, 196); \
        ddi_4 res197 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a197, b197, 197); \
        ddi_4 res198 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a198, b198, 198); \
        ddi_4 res199 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a199, b199, 199); \
        ddi_4 res200 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a200, b200, 200); \
        ddi_4 res201 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a201, b201, 201); \
        ddi_4 res202 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a202, b202, 202); \
        ddi_4 res203 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a203, b203, 203); \
        ddi_4 res204 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a204, b204, 204); \
        ddi_4 res205 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a205, b205, 205); \
        ddi_4 res206 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a206, b206, 206); \
        ddi_4 res207 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a207, b207, 207); \
        ddi_4 res208 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a208, b208, 208); \
        ddi_4 res209 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a209, b209, 209); \
        ddi_4 res210 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a210, b210, 210); \
        ddi_4 res211 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a211, b211, 211); \
        ddi_4 res212 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a212, b212, 212); \
        ddi_4 res213 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a213, b213, 213); \
        ddi_4 res214 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a214, b214, 214); \
        ddi_4 res215 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a215, b215, 215); \
        ddi_4 res216 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a216, b216, 216); \
        ddi_4 res217 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a217, b217, 217); \
        ddi_4 res218 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a218, b218, 218); \
        ddi_4 res219 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a219, b219, 219); \
        ddi_4 res220 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a220, b220, 220); \
        ddi_4 res221 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a221, b221, 221); \
        ddi_4 res222 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a222, b222, 222); \
        ddi_4 res223 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a223, b223, 223); \
        ddi_4 res224 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a224, b224, 224); \
        ddi_4 res225 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a225, b225, 225); \
        ddi_4 res226 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a226, b226, 226); \
        ddi_4 res227 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a227, b227, 227); \
        ddi_4 res228 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a228, b228, 228); \
        ddi_4 res229 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a229, b229, 229); \
        ddi_4 res230 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a230, b230, 230); \
        ddi_4 res231 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a231, b231, 231); \
        ddi_4 res232 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a232, b232, 232); \
        ddi_4 res233 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a233, b233, 233); \
        ddi_4 res234 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a234, b234, 234); \
        ddi_4 res235 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a235, b235, 235); \
        ddi_4 res236 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a236, b236, 236); \
        ddi_4 res237 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a237, b237, 237); \
        ddi_4 res238 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a238, b238, 238); \
        ddi_4 res239 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a239, b239, 239); \
        ddi_4 res240 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a240, b240, 240); \
        ddi_4 res241 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a241, b241, 241); \
        ddi_4 res242 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a242, b242, 242); \
        ddi_4 res243 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a243, b243, 243); \
        ddi_4 res244 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a244, b244, 244); \
        ddi_4 res245 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a245, b245, 245); \
        ddi_4 res246 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a246, b246, 246); \
        ddi_4 res247 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a247, b247, 247); \
        ddi_4 res248 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a248, b248, 248); \
        ddi_4 res249 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a249, b249, 249); \
        ddi_4 res250 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a250, b250, 250); \
        ddi_4 res251 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a251, b251, 251); \
        ddi_4 res252 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a252, b252, 252); \
        ddi_4 res253 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a253, b253, 253); \
        ddi_4 res254 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a254, b254, 254); \
        ddi_4 res255 = _igen_dd_ ## NAME ## _mm256_insertf128_pd(a255, b255, 255); \
                                         \
        _igen_dd_fb_mm256_store_pd(out_ddi+2048, res0); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2052, res1); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2056, res2); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2060, res3); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2064, res4); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2068, res5); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2072, res6); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2076, res7); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2080, res8); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2084, res9); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2088, res10); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2092, res11); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2096, res12); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2100, res13); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2104, res14); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2108, res15); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2112, res16); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2116, res17); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2120, res18); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2124, res19); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2128, res20); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2132, res21); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2136, res22); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2140, res23); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2144, res24); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2148, res25); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2152, res26); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2156, res27); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2160, res28); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2164, res29); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2168, res30); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2172, res31); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2176, res32); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2180, res33); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2184, res34); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2188, res35); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2192, res36); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2196, res37); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2200, res38); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2204, res39); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2208, res40); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2212, res41); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2216, res42); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2220, res43); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2224, res44); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2228, res45); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2232, res46); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2236, res47); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2240, res48); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2244, res49); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2248, res50); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2252, res51); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2256, res52); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2260, res53); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2264, res54); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2268, res55); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2272, res56); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2276, res57); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2280, res58); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2284, res59); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2288, res60); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2292, res61); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2296, res62); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2300, res63); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2304, res64); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2308, res65); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2312, res66); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2316, res67); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2320, res68); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2324, res69); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2328, res70); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2332, res71); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2336, res72); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2340, res73); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2344, res74); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2348, res75); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2352, res76); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2356, res77); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2360, res78); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2364, res79); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2368, res80); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2372, res81); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2376, res82); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2380, res83); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2384, res84); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2388, res85); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2392, res86); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2396, res87); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2400, res88); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2404, res89); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2408, res90); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2412, res91); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2416, res92); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2420, res93); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2424, res94); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2428, res95); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2432, res96); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2436, res97); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2440, res98); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2444, res99); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2448, res100); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2452, res101); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2456, res102); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2460, res103); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2464, res104); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2468, res105); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2472, res106); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2476, res107); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2480, res108); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2484, res109); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2488, res110); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2492, res111); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2496, res112); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2500, res113); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2504, res114); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2508, res115); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2512, res116); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2516, res117); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2520, res118); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2524, res119); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2528, res120); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2532, res121); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2536, res122); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2540, res123); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2544, res124); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2548, res125); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2552, res126); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2556, res127); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2560, res128); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2564, res129); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2568, res130); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2572, res131); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2576, res132); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2580, res133); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2584, res134); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2588, res135); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2592, res136); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2596, res137); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2600, res138); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2604, res139); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2608, res140); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2612, res141); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2616, res142); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2620, res143); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2624, res144); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2628, res145); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2632, res146); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2636, res147); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2640, res148); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2644, res149); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2648, res150); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2652, res151); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2656, res152); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2660, res153); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2664, res154); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2668, res155); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2672, res156); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2676, res157); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2680, res158); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2684, res159); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2688, res160); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2692, res161); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2696, res162); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2700, res163); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2704, res164); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2708, res165); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2712, res166); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2716, res167); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2720, res168); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2724, res169); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2728, res170); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2732, res171); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2736, res172); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2740, res173); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2744, res174); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2748, res175); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2752, res176); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2756, res177); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2760, res178); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2764, res179); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2768, res180); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2772, res181); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2776, res182); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2780, res183); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2784, res184); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2788, res185); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2792, res186); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2796, res187); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2800, res188); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2804, res189); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2808, res190); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2812, res191); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2816, res192); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2820, res193); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2824, res194); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2828, res195); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2832, res196); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2836, res197); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2840, res198); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2844, res199); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2848, res200); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2852, res201); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2856, res202); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2860, res203); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2864, res204); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2868, res205); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2872, res206); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2876, res207); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2880, res208); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2884, res209); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2888, res210); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2892, res211); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2896, res212); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2900, res213); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2904, res214); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2908, res215); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2912, res216); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2916, res217); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2920, res218); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2924, res219); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2928, res220); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2932, res221); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2936, res222); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2940, res223); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2944, res224); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2948, res225); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2952, res226); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2956, res227); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2960, res228); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2964, res229); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2968, res230); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2972, res231); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2976, res232); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2980, res233); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2984, res234); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2988, res235); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2992, res236); \
        _igen_dd_fb_mm256_store_pd(out_ddi+2996, res237); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3000, res238); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3004, res239); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3008, res240); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3012, res241); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3016, res242); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3020, res243); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3024, res244); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3028, res245); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3032, res246); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3036, res247); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3040, res248); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3044, res249); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3048, res250); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3052, res251); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3056, res252); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3060, res253); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3064, res254); \
        _igen_dd_fb_mm256_store_pd(out_ddi+3068, res255); \
    }

#define mm256_insertf128_pd_LAT(NAME) \
    static void mm256_insertf128_pd_ ## NAME ## _lat() { \
        for(int i = 0; i < BENCHMARK_ITER; ++i){ \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi42); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi41); \
            ddi40 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi40, ddi42); \
        } \
        out_ddi4[0] = ddi40; \
    }

#define mm256_insertf128_pd_GAP(NAME) \
    static void mm256_insertf128_pd_ ## NAME ## _gap() { \
        for(int i = 0; i < BENCHMARK_ITER; ++i){ \
            ddi41 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi41, ddi40); \
            ddi42 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi42, ddi40); \
            ddi43 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi43, ddi40); \
            ddi44 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi44, ddi40); \
    \
            ddi45 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi45, ddi40); \
            ddi46 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi46, ddi40); \
            ddi47 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi47, ddi40); \
            ddi48 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi48, ddi40); \
    \
            ddi49 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi49, ddi40); \
            ddi410 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi410, ddi40); \
            ddi411 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi411, ddi40); \
            ddi412 = _igen_dd_ ## NAME ## _mm256_unpackhi_pd(ddi412, ddi40); \
        } \
    \
        out_ddi4[1] = ddi41; \
        out_ddi4[2] = ddi42; \
        out_ddi4[3] = ddi43; \
        out_ddi4[4] = ddi44; \
        out_ddi4[5] = ddi45; \
        out_ddi4[6] = ddi46; \
        out_ddi4[7] = ddi47; \
        out_ddi4[8] = ddi48; \
        out_ddi4[9] = ddi49; \
        out_ddi4[10] = ddi410; \
        out_ddi4[11] = ddi411; \
        out_ddi4[12] = ddi412; \
    }
