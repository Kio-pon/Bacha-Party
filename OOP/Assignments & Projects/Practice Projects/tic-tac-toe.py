print('Tic Tac Toe!')
board = [
    ['.','.','.'],
    ['.','.','.'],
    ['.','.','.']
    ]

turn = False
symbols = ['X','O'] # X starts first

def print_board():
    for r in range(3):
        for c in range(3):
            print(board[r][c], end = ' ')
        print('')

def legality(row, col):
    if (row > 2) or (col > 2):
        print('ILLEGAL-1')
        return False
    if (row < 0) or (col < 0):
        print('ILLEGAL-2')
        return False
    if board[row][col] != '.':
        print('ILLEGAL-3')
        return False
    
    return True

def win_check():
    if board[0][0] == '.':
        return False
    else:
        check_1 = board[0][1] == board[0][0]
        check_2 = board[0][2] == board[0][0]
        if check_1 and check_2: return True

        check_3 = board[1][1] == board[0][0]
        check_4 = board[2][2] == board[0][0]
        if check_3 and check_4: return True

        check_5 = board[1][0] == board[0][0]
        check_6 = board[2][0] == board[0][0]
        if check_5 and check_6: return True

    if board[0][1] == '.':
        return False
    else:
        check_1 = board[1][1] == board[0][1]
        check_2 = board[2][1] == board[0][1]
        if check_1 and check_2: return True
    
    if board[0][2] == '.':
        return False
    else:
        check_1 = board[0][1] == board[0][2]
        check_2 = board[0][0] == board[0][2]
        if check_1 and check_2: return True

        check_3 = board[1][1] == board[0][2]
        check_4 = board[2][0] == board[0][2]
        if check_3 and check_4: return True

        check_5 = board[1][2] == board[0][2]
        check_6 = board[2][2] == board[0][2]
        if check_5 and check_6: return True
    
    if board[1][0] == '.':
        return False
    else:
        check_1 = board[1][1] == board[1][0]
        check_2 = board[1][2] == board[1][0]
        if check_1 and check_2: return True
    
    if board[2][0] == '.':
        return False
    else:
        check_1 = board[2][1] == board[2][0]
        check_2 = board[2][2] == board[2][0]
        if check_1 and check_2: return True
    
    return False

while (True):
    print("---------------------------")
    print(f'{symbols[turn]}\'s turn!')
    print("---------------------------")
    print_board()
    print("---------------------------")
    row = int(input('ROW: ')) # input by default is str
    col = int(input('COL: '))
    # the above line can give error if user inputs a string like "yes"
    # can be fixed but not interested right now

    if legality(row, col):
        board[row][col] = symbols[turn]
        if win_check():
            print_board()
            print(f'{symbols[turn]}\'s wins!!!')
            break
        turn = not(turn)
    
