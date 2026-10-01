MOD = 10**9 + 7


def total_sum(start: int, end: int) -> int:
	"""Returns the sum of all numbers in [start, end]."""
	return (end - start + 1) * (start + end) // 2


n = int(input())

total = 0
at = 1
while at <= n:
	add_amt = n // at  # Our divisor to process
	# The largest number that still has the same value of q
	last_same = n // add_amt

	total += add_amt * total_sum(at, last_same)
	at = last_same + 1

print(total % MOD)