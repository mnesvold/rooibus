define double @add_doubles(double %a, double %b) {
  %1 = fadd double %a, %b
  ret double %1
}

define double @sub_doubles(double %a, double %b) {
  %1 = fsub double %a, %b
  ret double %1
}

define double @mul_doubles(double %a, double %b) {
  %1 = fmul double %a, %b
  ret double %1
}

define double @div_doubles(double %a, double %b) {
  %1 = fdiv double %a, %b
  ret double %1
}

define double @rem_doubles(double %a, double %b) {
  %1 = frem double %a, %b
  ret double %1
}
