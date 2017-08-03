set in_dir=D:\work\protobuf_app\proto
set out_dir=D:\work\protobuf_app\proto

"D:\work\protobuf_app\google\protobuf\bin\protoc.exe" --proto_path=%in_dir% --cpp_out=%out_dir% ^
%in_dir%\basehead.proto ^
%in_dir%\protocal.proto
pause