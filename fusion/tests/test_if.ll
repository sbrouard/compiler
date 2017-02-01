define i32 @main(){
 %x1 = alloca i32
%x2 = alloca i32
%x3 = alloca i32
%x4 = add i32 0,0
  %x6 = add i32 %x4,0

 store i32 %x6, i32* %x1
%x8 = add i32 1,0
  %x10 = add i32 %x8,0

 store i32 %x10, i32* %x2
%x12 = add i32 0,0
  %x14 = add i32 %x12,0

 store i32 %x14, i32* %x3
%x19 = load i32, i32* %x1
 %x18 = icmp ne i32 %x19,0
 br i1 %x18, label %then19, label %endif19
 then19:
 %x16 = load i32, i32* %x3
%x17 = add i32 %x16,1
 store i32 %x17, i32* %x3
 br label %endif19
 endif19:
 %x21 = load i32, i32* %x1
 %x22 = load i32, i32* %x2
 %x23 = icmp slt i32 %x21,%x22
 %x26 = zext i1 %x23 to i32
 %x31 = icmp ne i32 %x26,0
 br i1 %x31, label %then32, label %else32
 then32:
 %x27 = load i32, i32* %x3
%x28 = add i32 %x27,1
 store i32 %x28, i32* %x3
 br label %endif32
 else32:
 %x29 = load i32, i32* %x3
%x30 = sub i32 %x29,1
 store i32 %x30, i32* %x3
 br label %endif32
 endif32:
ret i32 0
}

