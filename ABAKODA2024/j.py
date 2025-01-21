def solve_jumanji(n, a, b, c, damage):
    # Precompute dice probabilities
    dice_probs = {i: 0 for i in range(2, 13)}
    for x in range(1, 7):
        for y in range(1, 7):
            dice_probs[x + y] += 1 / 36

    # Memoization dictionary
    memo = {}

    def dp(pos_a, pos_b, pos_c, hp_a, hp_b, hp_c, turn):
        if hp_a <= 0 or hp_b <= 0 or hp_c <= 0:
            return 0.0
        if pos_a == n and pos_b == n and pos_c == n:
            return 1.0

        state = (pos_a, pos_b, pos_c, hp_a, hp_b, hp_c, turn)
        if state in memo:
            return memo[state]

        current_pos = [pos_a, pos_b, pos_c]
        current_hp = [hp_a, hp_b, hp_c]
        player = turn % 3

        total_prob = 0.0
        for roll, prob in dice_probs.items():
            new_pos = min(current_pos[player] + roll, n)
            new_hp = current_hp[player] - damage[new_pos]

            if new_hp <= 0:
                continue

            next_pos = current_pos[:]
            next_hp = current_hp[:]
            next_pos[player] = new_pos
            next_hp[player] = new_hp

            total_prob += prob * dp(
                next_pos[0], next_pos[1], next_pos[2],
                next_hp[0], next_hp[1], next_hp[2],
                turn + 1
            )

        memo[state] = total_prob
        return total_prob

    return dp(0, 0, 0, a, b, c, 0)

# Input
n, a, b, c = map(int, input().split())
damage = list(map(int, input().split()))

# Solve
result = solve_jumanji(n, a, b, c, damage)

# Output
print(f"{result:.12f}")
