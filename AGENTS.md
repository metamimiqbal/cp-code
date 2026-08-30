# Agent Guidance

## Repository Shape

- This repository is primarily a collection of independent competitive-programming solutions.
- Treat each solution as its own submission: most source files have their own `main` and should compile independently.
- Do not introduce shared libraries, project-wide refactors, or formatting changes unless the task explicitly requires them.
- Ignore generated artifacts such as `.bin`, `.exe`, `.dSYM`, `.cppNoExt`, and `.cph` files when choosing sources to edit.

## Build And Validation

- For C++, use GCC/G++ with C++17; GCC-only headers and builtins are intentional. See [README.md](README.md).
- Typical validation is:

  ```bash
  g++ -O2 -Wall path/to/file.cpp -o solution
  ./solution < input.txt
  ```

- Prefer the problem's sample tests or relevant fixtures under `.cph/` when available.
- Check multiple-test-case handling, integer overflow, bounds, and exact stdout formatting. There is no repository-wide test runner.
- Inspect `main()` before constructing input: files differ on whether they read a test-case count, and a few use `freopen` instead of standard input.
- The VS Code build task uses the machine-specific `/opt/homebrew/bin/g++-15`; prefer the documented compiler command when validating portability.
- Python and other educational or utility files may use their own runtime; validate them with the smallest relevant command.

## Finding Patterns

- Search by problem name, algorithm, or data structure before adding a new standalone implementation.
- Preserve existing contest conventions such as `bits/stdc++.h`, fast I/O, compact aliases, and local helper structures when editing a submission.
- Read [BITS_INTELLISENSE_TROUBLESHOOTING.md](BITS_INTELLISENSE_TROUBLESHOOTING.md) for editor/compiler issues and [GIT_NON_FAST_FORWARD_PUSH_RESOLUTION.md](GIT_NON_FAST_FORWARD_PUSH_RESOLUTION.md) for the documented Git recovery workflow.

## OpenRouter And LLM Work

- There is currently no OpenRouter integration, API client, environment configuration, or dependency declared in this repository. Do not assume one exists based on `download-llm.py`; that script downloads a Hugging Face model and is unrelated to OpenRouter.
- If adding OpenRouter functionality, keep it isolated from contest submissions and document the entry point, required model, request format, and local run command.
- Read credentials only from environment variables or an ignored local configuration file; never hard-code, print, commit, or place API keys in prompts, fixtures, logs, or generated files.
- Keep provider-specific code behind a small boundary so the rest of the project does not depend on OpenRouter details. Handle HTTP errors, timeouts, rate limits, malformed responses, and missing configuration explicitly.
- Add a focused smoke test using a mock or recorded response. Do not call a paid or authenticated endpoint as part of the default build or test command.
- Verify any new dependency is declared in the appropriate manifest and that the documented setup works from a clean checkout.

## Scope And Documentation

- Keep changes narrowly scoped to the requested problem or utility.
- Update relevant documentation when commands, configuration, or repository behavior changes; link to existing documentation rather than copying it.
- Do not remove unrelated user changes or generated files without an explicit request.
