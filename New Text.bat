@echo off
mkdir Basic
mkdir Arrays
mkdir Strings
mkdir Pointers
mkdir Structures
mkdir Functions
mkdir File-Handling
mkdir Dynamic-Memory-Allocation
mkdir Sorting-Algorithms
mkdir Searching-Algorithms
mkdir Data-Structures
mkdir Data-Structures\Linked-List
mkdir Data-Structures\Stack
mkdir Data-Structures\Queue
mkdir Data-Structures\Tree
mkdir Data-Structures\Graph
mkdir Algorithms
mkdir Algorithms\Recursion
mkdir Algorithms\Backtracking
mkdir Algorithms\Divide-and-Conquer
mkdir Algorithms\Greedy
mkdir Miscellaneous
mkdir Miscellaneous\Bitwise-Operators
mkdir Miscellaneous\Macros
mkdir Miscellaneous\Preprocessor-Directives
mkdir Miscellaneous\Multi-File-Programs
mkdir Projects

for /d %%i in (*) do (
    if not "%%i" == ".git" (
        cd "%%i"
        echo. > readme.md
        cd..
    )
)

echo Folder structure generated successfully.
