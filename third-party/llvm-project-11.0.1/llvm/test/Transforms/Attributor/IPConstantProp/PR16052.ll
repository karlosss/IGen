; NOTE: Assertions have been autogenerated by utils/update_test_checks.py UTC_ARGS: --function-signature --scrub-attributes
; RUN: opt -attributor -attributor-manifest-internal  -attributor-max-iterations-verify -attributor-annotate-decl-cs -attributor-max-iterations=2 -S < %s | FileCheck %s --check-prefixes=CHECK,NOT_CGSCC_NPM,NOT_CGSCC_OPM,NOT_TUNIT_NPM,IS__TUNIT____,IS________OPM,IS__TUNIT_OPM
; RUN: opt -aa-pipeline=basic-aa -passes=attributor -attributor-manifest-internal  -attributor-max-iterations-verify -attributor-annotate-decl-cs -attributor-max-iterations=2 -S < %s | FileCheck %s --check-prefixes=CHECK,NOT_CGSCC_OPM,NOT_CGSCC_NPM,NOT_TUNIT_OPM,IS__TUNIT____,IS________NPM,IS__TUNIT_NPM
; RUN: opt -attributor-cgscc -attributor-manifest-internal  -attributor-annotate-decl-cs -S < %s | FileCheck %s --check-prefixes=CHECK,NOT_TUNIT_NPM,NOT_TUNIT_OPM,NOT_CGSCC_NPM,IS__CGSCC____,IS________OPM,IS__CGSCC_OPM
; RUN: opt -aa-pipeline=basic-aa -passes=attributor-cgscc -attributor-manifest-internal  -attributor-annotate-decl-cs -S < %s | FileCheck %s --check-prefixes=CHECK,NOT_TUNIT_NPM,NOT_TUNIT_OPM,NOT_CGSCC_OPM,IS__CGSCC____,IS________NPM,IS__CGSCC_NPM

target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

define i64 @fn2() {
; IS__TUNIT____-LABEL: define {{[^@]+}}@fn2()
; IS__TUNIT____-NEXT:  entry:
; IS__TUNIT____-NEXT:    [[CALL2:%.*]] = call i64 @fn1(i64 undef) #0, !range !0
; IS__TUNIT____-NEXT:    ret i64 [[CALL2]]
;
; IS__CGSCC____-LABEL: define {{[^@]+}}@fn2()
; IS__CGSCC____-NEXT:  entry:
; IS__CGSCC____-NEXT:    [[CALL2:%.*]] = call i64 @fn1(i64 undef)
; IS__CGSCC____-NEXT:    ret i64 [[CALL2]]
;
entry:
  %conv = sext i32 undef to i64
  %div = sdiv i64 8, %conv
  %call2 = call i64 @fn1(i64 %div)
  ret i64 %call2
}

define i64 @fn2b(i32 %arg) {
; IS__TUNIT____-LABEL: define {{[^@]+}}@fn2b
; IS__TUNIT____-SAME: (i32 [[ARG:%.*]])
; IS__TUNIT____-NEXT:  entry:
; IS__TUNIT____-NEXT:    [[CONV:%.*]] = sext i32 [[ARG]] to i64
; IS__TUNIT____-NEXT:    [[DIV:%.*]] = sdiv i64 8, [[CONV]]
; IS__TUNIT____-NEXT:    [[CALL2:%.*]] = call i64 @fn1(i64 [[DIV]]) #0, !range !0
; IS__TUNIT____-NEXT:    ret i64 [[CALL2]]
;
; IS__CGSCC____-LABEL: define {{[^@]+}}@fn2b
; IS__CGSCC____-SAME: (i32 [[ARG:%.*]])
; IS__CGSCC____-NEXT:  entry:
; IS__CGSCC____-NEXT:    [[CONV:%.*]] = sext i32 [[ARG]] to i64
; IS__CGSCC____-NEXT:    [[DIV:%.*]] = sdiv i64 8, [[CONV]]
; IS__CGSCC____-NEXT:    [[CALL2:%.*]] = call i64 @fn1(i64 [[DIV]])
; IS__CGSCC____-NEXT:    ret i64 [[CALL2]]
;
entry:
  %conv = sext i32 %arg to i64
  %div = sdiv i64 8, %conv
  %call2 = call i64 @fn1(i64 %div)
  ret i64 %call2
}

define i64 @fn2c() {
; IS__TUNIT____-LABEL: define {{[^@]+}}@fn2c()
; IS__TUNIT____-NEXT:  entry:
; IS__TUNIT____-NEXT:    [[CALL2:%.*]] = call i64 @fn1(i64 42) #0, !range !0
; IS__TUNIT____-NEXT:    ret i64 [[CALL2]]
;
; IS__CGSCC____-LABEL: define {{[^@]+}}@fn2c()
; IS__CGSCC____-NEXT:  entry:
; IS__CGSCC____-NEXT:    ret i64 42
;
entry:
  %conv = sext i32 undef to i64
  %add = add i64 42, %conv
  %call2 = call i64 @fn1(i64 %add)
  ret i64 %call2
}

define internal i64 @fn1(i64 %p1) {
; CHECK-LABEL: define {{[^@]+}}@fn1
; CHECK-SAME: (i64 returned [[P1:%.*]])
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TOBOOL:%.*]] = icmp ne i64 [[P1]], 0
; CHECK-NEXT:    [[COND:%.*]] = select i1 [[TOBOOL]], i64 [[P1]], i64 [[P1]]
; CHECK-NEXT:    ret i64 [[COND]]
;
entry:
  %tobool = icmp ne i64 %p1, 0
  %cond = select i1 %tobool, i64 %p1, i64 %p1
  ret i64 %cond
}