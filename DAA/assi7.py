def print_board(board):
    for row in board:
        print(" ".join(row))
    print()

def is_safe(board, row, col):
    for i in range(col):
        if board[row][i] == 'Q':
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 'Q':
            return False

    for i, j in zip(range(row, len(board)), range(col, -1, -1)):
        if board[i][j] == 'Q':
            return False

    return True

def solve_n_queens_util(board, col):
    if col >= len(board):
        print_board(board)
        return True

    for i in range(len(board)):
        if is_safe(board, i, col):
            board[i][col] = 'Q'
            if solve_n_queens_util(board, col + 1):
                board[i][col] = '.'  
            else:
                board[i][col] = '.'

    return False

def solve_n_queens():
    n = 8
    board = [['.' for _ in range(n)] for _ in range(n)]
    board[0][0] = 'Q'
    solve_n_queens_util(board, 1) 

if __name__ == "__main__":
    solve_n_queens()

