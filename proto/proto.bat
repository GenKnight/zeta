set in_dir=D:\work\zeta\proto
set out_dir=D:\work\zeta\proto

"D:\work\zeta\google\protobuf\bin\protoc.exe" --proto_path=%in_dir% --cpp_out=%out_dir% ^
%in_dir%\basehead.proto ^
%in_dir%\protocal.proto ^
%in_dir%\risk_protocal.proto
pause