int countBits(unsigned int n) {
  int count;
  for (count = 0; n; count++) {
    n &= n - 1;
  }
  return count;
}

int roundUpToPowerOf2(int n) {
  n--;
  for (int i = 1; i < sizeof(n) * 8; i *= 2) {
    n |= n >> i;
  }
  return ++n;
}

void xorSwap(int &a, int &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}

int binaryAbs(int x) {
  int penultimate = (x >> (sizeof(x) * 8 - 1));
  return (x ^ penultimate) - penultimate;
}
