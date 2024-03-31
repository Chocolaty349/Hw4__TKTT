# Bài tập 4

Các chương trình được chạy bằng lệnh

```zsh
    ./tên chương trình
```

## 1. Bài toán đổi tiền (Change Coins)

Biên dịch bằng lệnh

```zsh
    cc -o change_coin change_coin.c
```

Chương trình nhận 1 tham số từ dòng lệnh là một chuỗi biểu thị một số nguyên dương, dư liệu được nạp sẵn là các mệnh giá của đồng VND. Ví dụ

```zsh
    chocolaty🍺chocolaty:~/Hw4_19000245_KhongVietAnh$ ./change_coin 34000
    Following is minimal number of change for 34000: 20000 10000 2000 2000 
```

## 2. Bài toán xếp balo 0-1 (0-1 Knapsack)

Biên dịch bằng lệnh;

```zsh
    cc -o knapsack knapsack.c
```

Chương trình sử dụng dữ liệu nạp sẵn từ sách của Anany, mục 3.4

## 3. Bài toán lập lịch sử dụng tài nguyên (Task schedualing)

Biên dịch bằng lệnh

```zsh
    cc -o activity activity.c
```

Chương trình sử dụng dữ liệu nạp sẵn từ slide bài giảng

## 4. Thuật toán Prim tìm cây bao trùm tối thiểu

Biên dịch bằng lệnh

```zsh
    cc -o prim prim.c
```

Chương trình sử dụng dữ liệu nạp sẵn là mảng 2 chiều biểu thị ma trận kề của đồ thị. Sinh ma trận mới bằng lệnh

```zsh
    python3 random_matrix.py n #n: cỡ của ma trận
```

## 5. Thuật toán Dijkstra

Biên dịch bằng lệnh

```zsh
    cc -o dijkstra_ssp djkstra_ssp.c
```

Chương trình sử dụng dữ liệu nạp sẵn là mảng 2 chiều biểu thị ma trận kề của đồ thị. Sinh ma trận mới bằng lệnh

```zsh
    python3 random_matrix.py n #n: cỡ của ma trận
```

## Exercise 9.1: 10

Trong mỗi bước lặp, thuật toán Prim chỉ xét tới những cạnh có một đầu là đỉnh chưa thuộc cây bao trùm, do đó cạnh mới thêm vào sẽ không thể nối 2 đỉnh đã thuộc cây từ trước đó và tạo thành chu trình, do đó không cần kiểm tra tính liên thông của đồ thị trước khi áp dụng thuật toán Prim

## Exercise 9.3: 2b

| Vertex | Distance from Source |
|--------|----------------------|
|   0    |          0           |
|   1    |          3           |
|   2    |          5           |
|   3    |          4           |
|   4    |          5           |
|   5    |          7           |
|   6    |          9           |
|   7    |          9           |
|   8    |          9           |
|   9    |         12           |
|  10    |         15           |
|  11    |         14           |
