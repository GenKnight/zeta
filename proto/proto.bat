set in_dir=D:\work\zeta\proto
set out_dir=D:\work\zeta\proto

"protoc.exe" --proto_path=%in_dir% --cpp_out=%out_dir% ^
basehead.proto ^
protocal.proto ^
risk_protocal.proto
pause