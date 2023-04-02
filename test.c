#include "check.h"
#include "s21_shunting_yard.h"

START_TEST(addition_1) {
  double answ;
  ck_assert_int_eq(parse("1+1", 0, &answ), 0);
  ck_assert_double_eq(answ, 2);
}
END_TEST

START_TEST(addition_2) {
  double answ;
  ck_assert_int_eq(parse("1+", 0, &answ), 1);
}
END_TEST

START_TEST(addition_3) {
  double answ;
  ck_assert_int_eq(parse("+1", 0, &answ), 0);
}
END_TEST

START_TEST(sub_1) {
  double answ;
  ck_assert_int_eq(parse("2.5-2", 0, &answ), 0);
  ck_assert_double_eq(answ, 0.5);
}
END_TEST

START_TEST(sub_2) {
  double answ;
  ck_assert_int_eq(parse("2.5-", 0, &answ), 1);
}
END_TEST

START_TEST(sub_3) {
  double answ;
  ck_assert_int_eq(parse("-2.5", 0, &answ), 0);
}
END_TEST

START_TEST(mul_1) {
  double answ;
  ck_assert_int_eq(parse("2.5*2", 0, &answ), 0);
  ck_assert_double_eq(answ, 5);
}
END_TEST

START_TEST(mul_2) {
  double answ;
  ck_assert_int_eq(parse("2.5*", 0, &answ), 1);
}
END_TEST

START_TEST(mul_3) {
  double answ;
  ck_assert_int_eq(parse("*2", 0, &answ), 1);
}
END_TEST

START_TEST(div_1) {
  double answ;
  ck_assert_int_eq(parse("5/2", 0, &answ), 0);
  ck_assert_double_eq(answ, 2.5);
}
END_TEST

START_TEST(div_2) {
  double answ;
  ck_assert_int_eq(parse("5/0", 0, &answ), 0);
  ck_assert_double_nan(answ);
}
END_TEST

START_TEST(div_3) {
  double answ;
  ck_assert_int_eq(parse("5/", 0, &answ), 1);
}
END_TEST

START_TEST(div_4) {
  double answ;
  ck_assert_int_eq(parse("/2", 0, &answ), 1);
}
END_TEST

START_TEST(pow_1) {
  double answ;
  ck_assert_int_eq(parse("16^0.25", 0, &answ), 0);
  ck_assert_double_eq(answ, 2);
}
END_TEST

START_TEST(pow_2) {
  double answ;
  ck_assert_int_eq(parse("2^4", 0, &answ), 0);
  ck_assert_double_eq(answ, 16);
}
END_TEST

START_TEST(pow_3) {
  double answ;
  ck_assert_int_eq(parse("(-0.25)^(1/3)", 0, &answ), 0);
  ck_assert_double_nan(answ);
}
END_TEST

START_TEST(pow_4) {
  double answ;
  ck_assert_int_eq(parse("(-0.25)^", 0, &answ), 1);
}
END_TEST

START_TEST(mod_1) {
  double answ;
  ck_assert_int_eq(parse("5 mod 2", 0, &answ), 0);
  ck_assert_double_eq(answ, 1);
}
END_TEST

START_TEST(cos_1) {
  double answ;
  ck_assert_int_eq(parse("cos(3.1415)", 0, &answ), 0);
  ck_assert_double_ge(1e-7, fabs(answ - -1));
}
END_TEST

START_TEST(sin_1) {
  double answ;
  ck_assert_int_eq(parse("sin(3.14159265359)", 0, &answ), 0);
  ck_assert_double_ge(1e-7, fabs(answ - 0));
}
END_TEST

START_TEST(tan_1) {
  double answ;
  ck_assert_int_eq(parse("tan(1.57079632679)", 0, &answ), 0);
  ck_assert_double_nan(answ);
}
END_TEST

START_TEST(tan_2) {
  double answ;
  ck_assert_int_eq(parse("tan(1)", 0, &answ), 0);
}
END_TEST

START_TEST(acos_1) {
  double answ;
  ck_assert_int_eq(parse("acos(0.1415926)", 0, &answ), 0);
  ck_assert_double_ge(1e-7, fabs(answ - 1.42872629));
}
END_TEST

START_TEST(acos_2) {
  double answ;
  ck_assert_int_eq(parse("acos(3.1415926)", 0, &answ), 0);
  ck_assert_double_nan(answ);
}
END_TEST

START_TEST(asin_1) {
  double answ;
  ck_assert_int_eq(parse("asin(0.1415926)", 0, &answ), 0);
  ck_assert_double_ge(1e-7, fabs(answ - 0.142070039));
}
END_TEST

START_TEST(asin_2) {
  double answ;
  ck_assert_int_eq(parse("asin(3.1415926)", 0, &answ), 0);
  ck_assert_double_nan(answ);
}
END_TEST

START_TEST(atan_1) {
  double answ;
  ck_assert_int_eq(parse("atan(3.1415926)", 0, &answ), 0);
  ck_assert_double_ge(1e-7, fabs(answ - 1.26262726));
}
END_TEST

START_TEST(sqrt_1) {
  double answ;
  ck_assert_int_eq(parse("sqrt(2)", 0, &answ), 0);
  ck_assert_double_ge(1e-7, fabs(answ - 1.41421356237));
}
END_TEST

START_TEST(sqrt_2) {
  double answ;
  ck_assert_int_eq(parse("sqrt(-2)", 0, &answ), 0);
  ck_assert_double_nan(answ);
}
END_TEST

START_TEST(ln_1) {
  double answ;
  ck_assert_int_eq(parse("ln(2)", 0, &answ), 0);
  ck_assert_double_ge(1e-7, fabs(answ - 0.69314718056));
}
END_TEST

START_TEST(ln_2) {
  double answ;
  ck_assert_int_eq(parse("ln(-2)", 0, &answ), 0);
  ck_assert_double_nan(answ);
}
END_TEST

START_TEST(log_1) {
  double answ;
  ck_assert_int_eq(parse("log(2)", 0, &answ), 0);
  ck_assert_double_ge(1e-7, fabs(answ - 0.30102999566));
}
END_TEST

START_TEST(log_2) {
  double answ;
  ck_assert_int_eq(parse("log(-2)", 0, &answ), 0);
  ck_assert_double_nan(answ);
}
END_TEST

START_TEST(other_1) {
  double answ;
  ck_assert_int_eq(parse("x", 4, &answ), 2);
  ck_assert_double_eq(answ, 4);
}
END_TEST

START_TEST(other_2) {
  double answ;
  ck_assert_int_eq(parse("1/x", 0, &answ), 2);
  ck_assert_double_nan(answ);
}
END_TEST

START_TEST(other_3) {
  double answ;
  ck_assert_int_eq(parse("acos(x)*", 2, &answ), 1);
  ck_assert_int_eq(parse("acos(x)*2", 2, &answ), 2);
  ck_assert_int_eq(parse("acos(x)*2", 0, &answ), 2);
}
END_TEST

START_TEST(other_4) {
  double answ;
  ck_assert_int_eq(parse("2*(4-2)", 2, &answ), 0);
  ck_assert_double_eq(answ, 4);
}
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("Check");
  TCase *tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, addition_1);
  tcase_add_test(tcase_core, addition_2);
  tcase_add_test(tcase_core, addition_3);
  tcase_add_test(tcase_core, sub_1);
  tcase_add_test(tcase_core, sub_2);
  tcase_add_test(tcase_core, sub_3);
  tcase_add_test(tcase_core, mul_1);
  tcase_add_test(tcase_core, mul_2);
  tcase_add_test(tcase_core, mul_3);
  tcase_add_test(tcase_core, div_1);
  tcase_add_test(tcase_core, div_2);
  tcase_add_test(tcase_core, div_3);
  tcase_add_test(tcase_core, div_4);
  tcase_add_test(tcase_core, pow_1);
  tcase_add_test(tcase_core, pow_2);
  tcase_add_test(tcase_core, pow_3);
  tcase_add_test(tcase_core, pow_4);
  tcase_add_test(tcase_core, mod_1);
  tcase_add_test(tcase_core, cos_1);
  tcase_add_test(tcase_core, sin_1);
  tcase_add_test(tcase_core, tan_1);
  tcase_add_test(tcase_core, tan_2);
  tcase_add_test(tcase_core, acos_1);
  tcase_add_test(tcase_core, acos_2);
  tcase_add_test(tcase_core, asin_1);
  tcase_add_test(tcase_core, asin_2);
  tcase_add_test(tcase_core, atan_1);
  tcase_add_test(tcase_core, sqrt_1);
  tcase_add_test(tcase_core, sqrt_2);
  tcase_add_test(tcase_core, ln_1);
  tcase_add_test(tcase_core, ln_2);
  tcase_add_test(tcase_core, log_1);
  tcase_add_test(tcase_core, log_2);
  tcase_add_test(tcase_core, other_1);
  tcase_add_test(tcase_core, other_2);
  tcase_add_test(tcase_core, other_3);
  tcase_add_test(tcase_core, other_4);

  suite_add_tcase(s, tcase_core);

  return s;
}

int main(void) {
  int nf;
  Suite *s1;
  SRunner *sr;
  s1 = lib_suite();
  sr = srunner_create(s1);

  // srunner_run_all(sr, CK_ENV);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);

  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
