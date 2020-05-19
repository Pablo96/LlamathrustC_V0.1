clang ^
-std=c17 ^
-DLT_DEBUG ^
-I"./include" ^
-o "bin/engine.exe" ^
-m64 ^
-lUser32.lib ^
-fcolor-diagnostics ^
-fomit-frame-pointer ^
-pedantic ^
-fsave-optimization-record=yaml ^
-foptimization-record-file="bin/optimizations.yml" ^
-Weverything ^
-Wno-unused-parameter ^
-fshow-source-location ^
-Og ^
-H ^
./src/Engine.c ./src/platform/Win32.c
