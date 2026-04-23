// Copyright 2026 ATF37

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// usage message
void print_usage() {
  printf("Usage: ./convert [-x|-b] num1 [num2 ...]\n");
}

// reverse string
void reverse(char *s) {
  int n = strlen(s);

  for (int i = 0; i < n / 2; i++) {
    char t = s[i];
    s[i] = s[n - i - 1];
    s[n - i - 1] = t;
  }
}

// binary conversion
void to_binary(int n, char *out) {
  char tmp[128];
  int i = 0, grp = 0;

  if (n == 0) {
    snprintf(out, sizeof(tmp), "%s", "0");
    return;
  }

  while (n > 0) {
    if (grp == 4) {
      tmp[i++] = ' ';
      grp = 0;
    }

    tmp[i++] = (n % 2) + '0';
    n /= 2;
    grp++;
  }

  tmp[i] = '\0';
  reverse(tmp);
  snprintf(out, sizeof(tmp), "%s", tmp);
}

// hex conversion
void to_hex(int n, char *out) {
  char tmp[128];
  int i = 0, grp = 0;

  if (n == 0) {
    snprintf(out, sizeof(tmp), "%s", "0");
    return;
  }

  while (n > 0) {
    if (grp == 2) {
      tmp[i++] = ' ';
      grp = 0;
    }

    int d = n % 16;

    if (d < 10) {
      tmp[i++] = d + '0';
    } else {
      tmp[i++] = (d - 10) + 'a';
    }

    n /= 16;
    grp++;
  }

  tmp[i] = '\0';
  reverse(tmp);
  snprintf(out, sizeof(tmp), "%s", tmp);
}

int main(int argc, char *argv[]) {
  int mode = 0;

  if (argc < 3) {
    print_usage();
    return 0;
  }

  if (strcmp(argv[1], "-x") == 0) {
    mode = 1;
  } else if (strcmp(argv[1], "-b") == 0) {
    mode = 2;
  } else {
    print_usage();
    return 0;
  }

  int start = 2;

  for (int i = start; i < argc; i++) {
    if (argv[i][0] == '-') {
      print_usage();
      return 0;
    }
  }

  for (int i = start; i < argc; i++) {
    int n = atoi(argv[i]);
    char res[128];

    if (mode == 1) {
      to_hex(n, res);
      printf("%d=0x%s\n", n, res);
    } else {
      to_binary(n, res);
      printf("%d=%s\n", n, res);
    }
  }

  return 0;
}
