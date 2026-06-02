input/code.cpp: In function 'int main()':
input/code.cpp:17:9: warning: 'void* memset(void*, int, size_t)' writing to an object of type 'pii' {aka 'struct std::pair<int, int>'} with no trivial copy-assignment [-Wclass-memaccess]
   17 |   memset(dp, 0x7f, sizeof(dp));
      |   ~~~~~~^~~~~~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/bits/stl_algobase.h:64,
                 from /usr/include/c++/11/bits/specfun.h:45,
                 from /usr/include/c++/11/cmath:1935,
                 from /usr/include/x86_64-linux-gnu/c++/11/bits/stdc++.h:41,
                 from input/code.cpp:1:
/usr/include/c++/11/bits/stl_pair.h:211:12: note: 'pii' {aka 'struct std::pair<int, int>'} declared here
  211 |     struct pair
      |            ^~~~
input/code.cpp:22:29: warning: suggest parentheses around comparison in operand of '&' [-Wparentheses]
   22 |                 if(i&(1<<l) == 0) {continue;}
      |                      ~~~~~~~^~~~