# Keisanki Joron 2 (Introduction to Computing II)
# Dept. of Engineering Systems, University of Tsukuba
# [UTF-8 / Unix]
# 計算機序論２・実習 (筑波大学工学システム学類)

# 2011/11/22a kameda[at]iit.tsukuba.ac.jp
# 02.3. bashとの連携

echo "This is just a bash script example."
echo "On bash, return-code-0 means success, and non-zero means error."

echo "-----------------"
./02-2-OpenFile-Full         && echo 'Test-1 passed!!' || echo 'Test-1 failed.'
echo "-----------------"
./02-2-OpenFile-Full abc.txt && echo 'Test-2 passed!!' || echo 'Test-2 failed.'
echo "-----------------"
./02-2-OpenFile-Full def.txt && echo 'Test-3 passed!!' || echo 'Test-3 failed.'

# This script itself should return interger value when it is treated as a script
exit 0 
