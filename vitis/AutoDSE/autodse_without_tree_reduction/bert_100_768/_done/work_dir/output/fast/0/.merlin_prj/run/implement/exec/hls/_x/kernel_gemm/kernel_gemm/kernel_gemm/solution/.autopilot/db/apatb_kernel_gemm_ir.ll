; ModuleID = '/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%struct.merlin_uint_128 = type { [16 x i8] }
%struct.merlin_uint_512 = type { [64 x i8] }

; Function Attrs: noinline
define void @apatb_kernel_gemm_ir(%struct.merlin_uint_512* noalias nocapture nonnull "fpga.decayed.dim.hint"="4800" "maxi" %C, %struct.merlin_uint_128* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="2500" "maxi" %A, %struct.merlin_uint_512* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="4800" "maxi" %B) local_unnamed_addr #0 {
entry:
  %malloccall = call i8* @malloc(i64 307200)
  %C_copy = bitcast i8* %malloccall to [4800 x i512]*
  %malloccall1 = call i8* @malloc(i64 40000)
  %A_copy = bitcast i8* %malloccall1 to [2500 x i128]*
  %malloccall2 = call i8* @malloc(i64 307200)
  %B_copy = bitcast i8* %malloccall2 to [4800 x i512]*
  %0 = bitcast %struct.merlin_uint_512* %C to [4800 x %struct.merlin_uint_512]*
  %1 = bitcast %struct.merlin_uint_128* %A to [2500 x %struct.merlin_uint_128]*
  %2 = bitcast %struct.merlin_uint_512* %B to [4800 x %struct.merlin_uint_512]*
  call fastcc void @copy_in([4800 x %struct.merlin_uint_512]* nonnull %0, [4800 x i512]* %C_copy, [2500 x %struct.merlin_uint_128]* nonnull %1, [2500 x i128]* %A_copy, [4800 x %struct.merlin_uint_512]* nonnull %2, [4800 x i512]* %B_copy)
  call void @apatb_kernel_gemm_hw([4800 x i512]* %C_copy, [2500 x i128]* %A_copy, [4800 x i512]* %B_copy)
  call void @copy_back([4800 x %struct.merlin_uint_512]* %0, [4800 x i512]* %C_copy, [2500 x %struct.merlin_uint_128]* %1, [2500 x i128]* %A_copy, [4800 x %struct.merlin_uint_512]* %2, [4800 x i512]* %B_copy)
  call void @free(i8* %malloccall)
  call void @free(i8* %malloccall1)
  call void @free(i8* %malloccall2)
  ret void
}

declare noalias i8* @malloc(i64) local_unnamed_addr

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_in([4800 x %struct.merlin_uint_512]* noalias readonly, [4800 x i512]* noalias, [2500 x %struct.merlin_uint_128]* noalias readonly, [2500 x i128]* noalias, [4800 x %struct.merlin_uint_512]* noalias readonly, [4800 x i512]* noalias) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0a4800struct.merlin_uint_512([4800 x i512]* %1, [4800 x %struct.merlin_uint_512]* %0)
  call fastcc void @onebyonecpy_hls.p0a2500struct.merlin_uint_128.26([2500 x i128]* %3, [2500 x %struct.merlin_uint_128]* %2)
  call fastcc void @onebyonecpy_hls.p0a4800struct.merlin_uint_512([4800 x i512]* %5, [4800 x %struct.merlin_uint_512]* %4)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a64i8([64 x i8]* %dst, [64 x i8]* readonly %src, i64 %num) local_unnamed_addr #2 {
entry:
  %0 = icmp eq [64 x i8]* %src, null
  %1 = icmp eq [64 x i8]* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [64 x i8], [64 x i8]* %dst, i64 0, i64 %for.loop.idx2
  %src.addr = getelementptr [64 x i8], [64 x i8]* %src, i64 0, i64 %for.loop.idx2
  %3 = load i8, i8* %src.addr, align 1
  store i8 %3, i8* %dst.addr, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @onebyonecpy_hls.p0a2500struct.merlin_uint_128([2500 x %struct.merlin_uint_128]* noalias %dst, [2500 x i128]* noalias readonly %src) unnamed_addr #3 {
entry:
  %0 = icmp eq [2500 x %struct.merlin_uint_128]* %dst, null
  %1 = icmp eq [2500 x i128]* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @arraycpy_hls.p0a2500struct.merlin_uint_128([2500 x %struct.merlin_uint_128]* nonnull %dst, [2500 x i128]* nonnull %src, i64 2500)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a2500struct.merlin_uint_128([2500 x %struct.merlin_uint_128]* %dst, [2500 x i128]* readonly %src, i64 %num) local_unnamed_addr #2 {
entry:
  %0 = icmp eq [2500 x i128]* %src, null
  %1 = icmp eq [2500 x %struct.merlin_uint_128]* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond3 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond3, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx4 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %3 = getelementptr [2500 x i128], [2500 x i128]* %src, i64 0, i64 %for.loop.idx4
  %dst.addr.02 = getelementptr [2500 x %struct.merlin_uint_128], [2500 x %struct.merlin_uint_128]* %dst, i64 0, i64 %for.loop.idx4, i32 0
  call void @arraycpy_hls.p0a16i8([16 x i8]* %dst.addr.02, i128* %3, i64 0, i64 16)
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx4, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a16i8([16 x i8]* %dst, i128* readonly %src, i64 %src_idx, i64 %num) local_unnamed_addr #2 {
entry:
  %0 = icmp eq i128* %src, null
  %1 = icmp eq [16 x i8]* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [16 x i8], [16 x i8]* %dst, i64 0, i64 %for.loop.idx2
  %3 = mul i64 8, %for.loop.idx2
  %4 = add i64 %src_idx, %3
  %5 = load i128, i128* %src, align 1
  %6 = zext i64 %4 to i128
  %7 = lshr i128 %5, %6
  %.partselect = trunc i128 %7 to i8
  store i8 %.partselect, i8* %dst.addr, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_out([4800 x %struct.merlin_uint_512]* noalias, [4800 x i512]* noalias readonly, [2500 x %struct.merlin_uint_128]* noalias, [2500 x i128]* noalias readonly, [4800 x %struct.merlin_uint_512]* noalias, [4800 x i512]* noalias readonly) unnamed_addr #4 {
entry:
  call fastcc void @onebyonecpy_hls.p0a4800struct.merlin_uint_512.6([4800 x %struct.merlin_uint_512]* %0, [4800 x i512]* %1)
  call fastcc void @onebyonecpy_hls.p0a2500struct.merlin_uint_128([2500 x %struct.merlin_uint_128]* %2, [2500 x i128]* %3)
  call fastcc void @onebyonecpy_hls.p0a4800struct.merlin_uint_512.6([4800 x %struct.merlin_uint_512]* %4, [4800 x i512]* %5)
  ret void
}

declare void @free(i8*) local_unnamed_addr

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @onebyonecpy_hls.p0a4800struct.merlin_uint_512.6([4800 x %struct.merlin_uint_512]* noalias %dst, [4800 x i512]* noalias readonly %src) unnamed_addr #3 {
entry:
  %0 = icmp eq [4800 x %struct.merlin_uint_512]* %dst, null
  %1 = icmp eq [4800 x i512]* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @arraycpy_hls.p0a4800struct.merlin_uint_512.9([4800 x %struct.merlin_uint_512]* nonnull %dst, [4800 x i512]* nonnull %src, i64 4800)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a4800struct.merlin_uint_512.9([4800 x %struct.merlin_uint_512]* %dst, [4800 x i512]* readonly %src, i64 %num) local_unnamed_addr #2 {
entry:
  %0 = icmp eq [4800 x i512]* %src, null
  %1 = icmp eq [4800 x %struct.merlin_uint_512]* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond3 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond3, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx4 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %3 = getelementptr [4800 x i512], [4800 x i512]* %src, i64 0, i64 %for.loop.idx4
  %dst.addr.02 = getelementptr [4800 x %struct.merlin_uint_512], [4800 x %struct.merlin_uint_512]* %dst, i64 0, i64 %for.loop.idx4, i32 0
  call void @arraycpy_hls.p0a64i8.12([64 x i8]* %dst.addr.02, i512* %3, i64 0, i64 64)
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx4, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a64i8.12([64 x i8]* %dst, i512* readonly %src, i64 %src_idx, i64 %num) local_unnamed_addr #2 {
entry:
  %0 = icmp eq i512* %src, null
  %1 = icmp eq [64 x i8]* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [64 x i8], [64 x i8]* %dst, i64 0, i64 %for.loop.idx2
  %3 = mul i64 8, %for.loop.idx2
  %4 = add i64 %src_idx, %3
  %5 = load i512, i512* %src, align 1
  %6 = zext i64 %4 to i512
  %7 = lshr i512 %5, %6
  %.partselect = trunc i512 %7 to i8
  store i8 %.partselect, i8* %dst.addr, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @onebyonecpy_hls.p0a4800struct.merlin_uint_512([4800 x i512]* noalias %dst, [4800 x %struct.merlin_uint_512]* noalias readonly %src) unnamed_addr #3 {
entry:
  %0 = icmp eq [4800 x i512]* %dst, null
  %1 = icmp eq [4800 x %struct.merlin_uint_512]* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @arraycpy_hls.p0a4800struct.merlin_uint_512.19([4800 x i512]* nonnull %dst, [4800 x %struct.merlin_uint_512]* nonnull %src, i64 4800)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a4800struct.merlin_uint_512.19([4800 x i512]* %dst, [4800 x %struct.merlin_uint_512]* readonly %src, i64 %num) local_unnamed_addr #2 {
entry:
  %0 = icmp eq [4800 x %struct.merlin_uint_512]* %src, null
  %1 = icmp eq [4800 x i512]* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond3 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond3, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx4 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %src.addr.01 = getelementptr [4800 x %struct.merlin_uint_512], [4800 x %struct.merlin_uint_512]* %src, i64 0, i64 %for.loop.idx4, i32 0
  %3 = getelementptr [4800 x i512], [4800 x i512]* %dst, i64 0, i64 %for.loop.idx4
  call void @arraycpy_hls.p0a64i8.22(i512* %3, i64 0, [64 x i8]* %src.addr.01, i64 64)
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx4, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a64i8.22(i512* %dst, i64 %dst_idx, [64 x i8]* readonly %src, i64 %num) local_unnamed_addr #2 {
entry:
  %0 = icmp eq [64 x i8]* %src, null
  %1 = icmp eq i512* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %3 = mul i64 8, %for.loop.idx2
  %4 = add i64 %dst_idx, %3
  %src.addr = getelementptr [64 x i8], [64 x i8]* %src, i64 0, i64 %for.loop.idx2
  %5 = load i8, i8* %src.addr, align 1
  %6 = load i512, i512* %dst, align 1
  %7 = zext i64 %4 to i512
  %8 = shl i512 255, %7
  %9 = zext i8 %5 to i512
  %10 = shl i512 %9, %7
  %thr.xor1 = xor i512 %8, -1
  %thr.and2 = and i512 %6, %thr.xor1
  %thr.or3 = or i512 %thr.and2, %10
  store i512 %thr.or3, i512* %dst, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @onebyonecpy_hls.p0a2500struct.merlin_uint_128.26([2500 x i128]* noalias %dst, [2500 x %struct.merlin_uint_128]* noalias readonly %src) unnamed_addr #3 {
entry:
  %0 = icmp eq [2500 x i128]* %dst, null
  %1 = icmp eq [2500 x %struct.merlin_uint_128]* %src, null
  %2 = or i1 %0, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @arraycpy_hls.p0a2500struct.merlin_uint_128.29([2500 x i128]* nonnull %dst, [2500 x %struct.merlin_uint_128]* nonnull %src, i64 2500)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a2500struct.merlin_uint_128.29([2500 x i128]* %dst, [2500 x %struct.merlin_uint_128]* readonly %src, i64 %num) local_unnamed_addr #2 {
entry:
  %0 = icmp eq [2500 x %struct.merlin_uint_128]* %src, null
  %1 = icmp eq [2500 x i128]* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond3 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond3, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx4 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %src.addr.01 = getelementptr [2500 x %struct.merlin_uint_128], [2500 x %struct.merlin_uint_128]* %src, i64 0, i64 %for.loop.idx4, i32 0
  %3 = getelementptr [2500 x i128], [2500 x i128]* %dst, i64 0, i64 %for.loop.idx4
  call void @arraycpy_hls.p0a16i8.32(i128* %3, i64 0, [16 x i8]* %src.addr.01, i64 16)
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx4, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @arraycpy_hls.p0a16i8.32(i128* %dst, i64 %dst_idx, [16 x i8]* readonly %src, i64 %num) local_unnamed_addr #2 {
entry:
  %0 = icmp eq [16 x i8]* %src, null
  %1 = icmp eq i128* %dst, null
  %2 = or i1 %1, %0
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %3 = mul i64 8, %for.loop.idx2
  %4 = add i64 %dst_idx, %3
  %src.addr = getelementptr [16 x i8], [16 x i8]* %src, i64 0, i64 %for.loop.idx2
  %5 = load i8, i8* %src.addr, align 1
  %6 = load i128, i128* %dst, align 1
  %7 = zext i64 %4 to i128
  %8 = shl i128 255, %7
  %9 = zext i8 %5 to i128
  %10 = shl i128 %9, %7
  %thr.xor1 = xor i128 %8, -1
  %thr.and2 = and i128 %6, %thr.xor1
  %thr.or3 = or i128 %thr.and2, %10
  store i128 %thr.or3, i128* %dst, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

declare void @apatb_kernel_gemm_hw([4800 x i512]*, [2500 x i128]*, [4800 x i512]*)

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_back([4800 x %struct.merlin_uint_512]* noalias, [4800 x i512]* noalias readonly, [2500 x %struct.merlin_uint_128]* noalias, [2500 x i128]* noalias readonly, [4800 x %struct.merlin_uint_512]* noalias, [4800 x i512]* noalias readonly) unnamed_addr #4 {
entry:
  call fastcc void @onebyonecpy_hls.p0a4800struct.merlin_uint_512.6([4800 x %struct.merlin_uint_512]* %0, [4800 x i512]* %1)
  ret void
}

define void @kernel_gemm_hw_stub_wrapper([4800 x i512]*, [2500 x i128]*, [4800 x i512]*) #5 {
entry:
  %malloccall = tail call i8* @malloc(i64 307200)
  %3 = bitcast i8* %malloccall to [4800 x %struct.merlin_uint_512]*
  %malloccall1 = tail call i8* @malloc(i64 40000)
  %4 = bitcast i8* %malloccall1 to [2500 x %struct.merlin_uint_128]*
  %malloccall2 = tail call i8* @malloc(i64 307200)
  %5 = bitcast i8* %malloccall2 to [4800 x %struct.merlin_uint_512]*
  call void @copy_out([4800 x %struct.merlin_uint_512]* %3, [4800 x i512]* %0, [2500 x %struct.merlin_uint_128]* %4, [2500 x i128]* %1, [4800 x %struct.merlin_uint_512]* %5, [4800 x i512]* %2)
  %6 = bitcast [4800 x %struct.merlin_uint_512]* %3 to %struct.merlin_uint_512*
  %7 = bitcast [2500 x %struct.merlin_uint_128]* %4 to %struct.merlin_uint_128*
  %8 = bitcast [4800 x %struct.merlin_uint_512]* %5 to %struct.merlin_uint_512*
  call void @kernel_gemm_hw_stub(%struct.merlin_uint_512* %6, %struct.merlin_uint_128* %7, %struct.merlin_uint_512* %8)
  call void @copy_in([4800 x %struct.merlin_uint_512]* %3, [4800 x i512]* %0, [2500 x %struct.merlin_uint_128]* %4, [2500 x i128]* %1, [4800 x %struct.merlin_uint_512]* %5, [4800 x i512]* %2)
  ret void
}

declare void @kernel_gemm_hw_stub(%struct.merlin_uint_512*, %struct.merlin_uint_128*, %struct.merlin_uint_512*)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="arraycpy_hls" }
attributes #3 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #4 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyout" }
attributes #5 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
