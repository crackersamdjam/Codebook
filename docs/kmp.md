`pi[i]` = the length of the longest proper prefix of `s` (i.e. `s[0, i-1]`) that is also a suffix of `s[0, i-1]`.

To check if `t` contains `s`, do kmp on `s+'#'+t` and check whether any `pi[i] = len(s)`.
