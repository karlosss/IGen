#!/bin/bash

python ../bin/igen.py "$1" $2 -o /tmp/out.cpp
fun=$(grep -v '#include' /tmp/out.cpp)

if [[ -n "$2" && "$2" = -R ]]
then
  out_file=/tmp/igen_
else
  out_file=/tmp/igen_herbie_
fi

decl_line=$(grep -E '^f64_I f\(.*\{' <<< "$fun")
num_args=$(($(grep -o 'f64_I' <<< "$decl_line" | wc -l) - 1))

bounds_decl=""
f64i_decl=""
call_args=""

for i in $(seq 1 1 $num_args)
do
  b="double x${i}up = std::stod(std::string(argv[$((2*$i-1))])); double x${i}lo = neg(std::string(argv[$((2*$i))]));
"
  bounds_decl="$bounds_decl$b"
  f64i="f64_I x${i} = _ia_set_f64(x${i}lo, x${i}up);
"
  f64i_decl="$f64i_decl$f64i"
  call_args="$call_args, x${i}"
done

call_args="($(cut -c3- <<< "$call_args"))"
funcall="f$call_args;"

template=$(cat accuracy_template.cpp)
python -c 'import sys; print(sys.argv[1].replace("BOUNDS_DECL", sys.argv[2]).replace("F64I_DECL", sys.argv[3]).replace("FUNCALL", sys.argv[4]).replace("FUNCTION", sys.argv[5]))' "$template" "$bounds_decl" "$f64i_decl" "$funcall" "$fun" > "${out_file}accuracy.cpp"
template=$(cat runtime_template.cpp)
python -c 'import sys; print(sys.argv[1].replace("BOUNDS_DECL", sys.argv[2]).replace("F64I_DECL", sys.argv[3]).replace("FUNCALL", sys.argv[4]).replace("FUNCTION", sys.argv[5]))' "$template" "$bounds_decl" "$f64i_decl" "$funcall" "$fun" > "${out_file}runtime.cpp"
