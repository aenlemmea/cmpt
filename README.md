## cmpt (cry tool)

Tool to help with competitive programming. Use [Competitive Companion](https://github.com/jmerle/competitive-companion) as an extension for fetching.

### USAGE:

1. `cry fo` 

Fetches one problem. Equivalent to `cry --fetch-one`

-----

2. `cry fc` 

Fetches entire contest. Equivalent to `cry --fetch-contest`

-----

3. `cry rn <binary-name>`

Run the binary-name. If binary-name is not found, attempts to compile and run from source file that matches binary-name. If no source file found, reports error

-----

4. `cry rt <binary-name>`

Test the binary name with the prefetched test.in and test.out files. If binary-name is not found, attempt to compile, run and test. Compilation criteria is same as for `cry rn`

-----

5. `cry config <--template> <--template-alias>|<--compile-flags> <--flag-preset-name>|`

Only running `cry config` shows you what the current config is. 

Set the template file and a alias for it or the compiler flags. 

The base minimul compile-flag is set to `-Wall -Wextra -O2 -std=c++20 -Wconversion -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address`. Currently `g++` support is baked in, `clang++` support is due.

-----

6. `cry clean <...contest-id>|<problem-id>| rm <--template-alias>`

Only running `cry clean` would attempt to clear 

WARNING. Attempts to delete all the binary-name. If ran with contest-id, deletes all binaries found in that directory. Multiple contest-ids can be stated. The last part allows deleting templates. Note: the default template CANNOT be deleted under any circumstance.

-----

7. `cry ape <problem-id>`

[Low Priority] Equivalent to `cry --apetize <problem-id>` to dump the problem to any local LLM model and get a much cleaner reading statement. 


### BUILDING

1. CMake will auto populate the deps and recursively hydrate the submodules. (`Crow` framework for the http server).
2. You will manually need to install the `asio-dev` or `asio-devel` library for their headers (needed by crow).
3. Rest create a `build` directory, enter it as: `mkdir -p build && cd build`
4. Run `cmake .. -G "Unix Makefiles"`. or, instead of step 3 and 4: you can run `./build.sh` and it will do everything for you.
5. Run `./build.sh` to get a clean slate.

### DIRECTORY STYLE:

For `cry fo <problem-id>`

```
A2019/
├── sol.cpp
├── test_case.in
└── test_case.out

```
#### TODO

[] Support template placement strategies (viz. OVERWRITE or ADD_DUP)
[] Clang++ support for compilation flags
[] Custom directory structre or Alternate directory structure.
[] (Multithreading) Experiment with placing files first in a temp directory then mv after data is fetched. 
[] Color support.
[] Integrate fzf for template pickers.

#### Why `cry`?

Well, the plan was to use `cmp`, but `cmp` is already used as a tool in GNU/Linux environment, hence had to settle for `cry`. Feel free to alias.
