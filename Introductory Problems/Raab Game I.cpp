input/code.cpp: In function 'int main()':
input/code.cpp:4:19: warning: this 'for' clause does not guard... [-Wmisleading-indentation]
    4 | #define REP(i, n) for(int i = 1; i <= (n); i++)
      |                   ^~~
input/code.cpp:34:9: note: in expansion of macro 'REP'
   34 |         REP(i, n) cout << f[i] << " "; cout << "\n";
      |         ^~~
input/code.cpp:34:40: note: ...this statement, but the latter is misleadingly indented as if it were guarded by the 'for'
   34 |         REP(i, n) cout << f[i] << " "; cout << "\n";
      |                                        ^~~~
input/code.cpp:4:19: warning: this 'for' clause does not guard... [-Wmisleading-indentation]
    4 | #define REP(i, n) for(int i = 1; i <= (n); i++)
      |                   ^~~
input/code.cpp:35:9: note: in expansion of macro 'REP'
   35 |         REP(i, n) cout << s[i] << " "; cout << "\n";
      |         ^~~
input/code.cpp:35:40: note: ...this statement, but the latter is misleadingly indented as if...