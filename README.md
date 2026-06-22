# cp-code

Solutions to competitive programming problems from Codeforces, AtCoder, CSES, and similar platforms.

This is not production code. It's contest code — written under time pressure, optimized for the judge, and intentionally structured around CP conventions: `bits/stdc++.h`, global arrays, short names, and macros. Don't treat it as a style reference for anything else.

---

## Prerequisites

- **GCC/G++ with C++17** — most solutions use GCC-specific headers and builtins
- `<bits/stdc++.h>` — GCC only; not available in Clang by default

If you're on macOS with Apple Clang, either install GCC via Homebrew (`brew install gcc`) or set up a [bits/stdc++.h shim](https://stackoverflow.com/questions/21430030/how-to-include-bits-stdc-h-in-xcode). The shim approach works but occasionally breaks on newer Clang versions — GCC is more reliable.

MSVC won't work. `__builtin_popcount`, `__gcd`, and similar GCC intrinsics are used throughout.

---

## Compilation & Execution

```bash
g++ -O2 -Wall A_Almost_Prime.cpp -o solution
./solution < input.txt
```

`-O2` matches what most online judges run. Skipping it won't break anything, but the timing won't reflect judge behavior.

Solutions read from `stdin`, write to `stdout`. No file I/O unless the problem explicitly required it.

---

## Repository Structure

Files are organized by problem ID and name. Almost everything is a single standalone `.cpp` file.

**Naming:**
- `A_Almost_Prime.cpp` — round-relative label (Div. 2 problem A, B, C...)
- `136A-Presents.cpp` — absolute platform ID + problem name
- `Array_Division/`, `Add_Permutation/` — multi-file problems or algorithm templates that didn't fit cleanly in one file

The `Al_Aqsa` and `resources` directories contain unrelated project work and are not part of this archive.

---

## Code Patterns

Every file follows the same general shape:

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Fast I/O — without this, large inputs will TLE on some judges
ios_base::sync_with_stdio(false);
cin.tie(NULL);

void solve() {
    // problem logic
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
```

Common abbreviations: `ll` → `long long`, `vi` → `vector<int>`, `all(x)` → `x.begin(), x.end()`.

If any shortcut or name is unclear, look at how it's used in context mentioned with **"typedef"**

---

## Embedded Utilities

There's no shared utility library. Reusable structures (Segment Trees, Fenwick Trees, DSU, modular exponentiation) are copied directly into whichever problem file needs them. This is deliberate — each file compiles independently, which makes it easier to submit and test in isolation.

If you're looking for a clean implementation of something specific, search by structure name across files. You'll find multiple versions; pick the one from a problem where that structure was the core constraint, not a peripheral tool — those tend to be more carefully written.

---

## Known Limitations

**Dead code is real.** Commented-out `cerr` debug lines, unused template fragments, and leftover variable declarations are contest artifacts. They don't affect correctness, but they're there.

**"Correct" means the judge accepted it** — not that it handles all edge cases imaginable. Some solutions may have assumptions baked in that the problem constraints guaranteed (e.g., no negative input, no duplicate values) that aren't enforced in the code itself.

**No comments explaining the approach.** If you want to understand the logic, work through the problem first, then read the code. Reading the code cold on harder problems (Div. 1 C and above) without knowing the intended algorithm is a bad experience.
