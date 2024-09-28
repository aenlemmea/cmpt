## cry Tool

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

Test the binary name with the prefetched test\_case.in and test\_case.out files. If binary-name is not found, attempt to compile, run and test. Compilation criteria is same as for `cry rn`

-----

5. `cry config <--template>|<--compile-flags>|<--test-req>|<--clean-args>`

Set the template file or the compiler flags or the testing requirements. Set cleaning arguments for what files with stated extensions will be removed by `cry clean`

-----

6. `cry clean <...contest-id>|<problem-id>`

WARNING. Attempts to delete all the binary-name. If ran with contest-id, deletes all binaries found in that directory. Multiple contest-ids can be stated

-----

7. `cry ape <problem-id>`

[Low Priority] Equivalent to `cry --apetize <problem-id>` to dump the problem to any local LLM model and get a much cleaner reading statement. 


### DIRECTORY STYLE:

For `cry fo <problem-id>`

```
A2019/
├── sol.cpp
├── test_case.in
└── test_case.out

```
#### Why `cry`?

Well, the plan was to use `cmp`, but `cmp` is already used as a tool in GNU/Linux environment, hence had to settle for `cry`. Feel free to alias.
