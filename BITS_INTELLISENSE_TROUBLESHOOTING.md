# bits/stdc++.h and IntelliSense on macOS

This note explains why `#include <bits/stdc++.h>` may or may not show a red squiggle in VS Code, and how to configure VS Code so it uses Homebrew GCC instead of Apple Clang.

## What the red mark means

If IntelliSense underlines `#include <bits/stdc++.h>`, VS Code usually cannot find that header with the compiler it is using.

Important detail:

- `bits/stdc++.h` is a GCC-specific header.
- Apple Clang on macOS usually does not provide it.
- Homebrew GCC does provide it.

So if you use GCC, the include should resolve. If VS Code is pointing at Clang, the include may look broken even though your build command works.

## What to use on macOS

For Homebrew GCC, the compiler path is often one of these:

- `/opt/homebrew/bin/g++-15`
- `/usr/local/bin/g++-15`

Use the path that exists on your machine.

Check it in Terminal:

```bash
which g++-15
```

Then confirm the version:

```bash
g++-15 --version
```

## Reconfigure IntelliSense

Open VS Code and do this:

1. Open Command Palette.
2. Run `C/C++: Edit Configurations (UI)`.
3. Set `Compiler path` to your GCC binary, for example:

```text
/opt/homebrew/bin/g++-15
```

4. Set `IntelliSense mode` to a GCC mode, usually:

```text
macos-gcc-arm64
```

or

```text
macos-gcc-x64
```

depending on your Mac and toolchain.

5. Set the language standard you want, for example:

```text
gnu++17
```

6. Run `C/C++: Reset IntelliSense Database`.
7. Reload VS Code.

## How to tell if it is fixed

You should see one of these signs:

- The red mark on `#include <bits/stdc++.h>` disappears.
- The C/C++ output panel shows your GCC path.
- IntelliSense logs mention a GCC-based mode instead of Clang.

If you see a log like this, the configuration is working:

```text
querying compilerPath: "/opt/homebrew/bin/g++-15"
IntelliSenseMode was changed to "macos-gcc-arm64"
```

## If it still shows a red mark

Check these common causes:

- VS Code is using `/usr/bin/clang` instead of Homebrew GCC.
- The include path was not refreshed after changing compiler path.
- You edited the build task, but not the C/C++ configuration.
- The wrong configuration is active for the file type.

## Fast checklist

- `which g++-15` returns a Homebrew path.
- `Compiler path` in VS Code matches that path.
- `IntelliSense mode` is GCC-based.
- IntelliSense database has been reset.
- The file is a `.cpp` file, not a C file.

## Practical rule

If your build task uses GCC and IntelliSense uses Clang, VS Code can show false errors even when compilation succeeds. Keep both aligned to the same compiler family.
