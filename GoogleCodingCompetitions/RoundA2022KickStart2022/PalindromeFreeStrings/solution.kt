fun match(s: Int, t: String): Boolean {
    for (i in t.indices) {
        if (((s shr i) and 1) != (t[i] - '0') && t[i] != '?') {
            return false
        }
    }
    return true
}

fun main() {
    val test = readLine()!!.toInt()
    val palindrome5 =
        setOf(
            "00000".toInt(2),
            "00100".toInt(2),
            "01010".toInt(2),
            "01110".toInt(2),
            "10001".toInt(2),
            "10101".toInt(2),
            "11011".toInt(2),
            "11111".toInt(2),
        )
    val palindrome6 =
        setOf(
            "000000".toInt(2),
            "001100".toInt(2),
            "010010".toInt(2),
            "011110".toInt(2),
            "100001".toInt(2),
            "101101".toInt(2),
            "110011".toInt(2),
            "111111".toInt(2),
        )
    for (t in 1..test) {
        readLine()!!
        val s = readLine()!!
        val dp = Array(s.length) { if (it < 4) Array(32) { true } else Array(32) { false } }
        for (i in 4 until s.length) {
            for (j in 0 until 32) {
                if (match(j, s.substring(i - 4, i + 1)) && !palindrome5.contains(j)) {
                    if (i == 4) {
                        dp[i][j] = true
                    } else {
                        if (s[i - 5] == '0' || s[i - 5] == '?') {
                            val candidate = (j shl 1) or 0
                            if (!palindrome6.contains(candidate)) {
                                dp[i][j] = dp[i][j] or dp[i - 1][candidate and 31]
                            }
                        }
                        if (s[i - 5] == '1' || s[i - 5] == '?') {
                            val candidate = (j shl 1) or 1
                            if (!palindrome6.contains(candidate)) {
                                dp[i][j] = dp[i][j] or dp[i - 1][candidate and 31]
                            }
                        }
                    }
                }
            }
        }
        val possible = dp[s.length - 1].any { it }
        println("Case #$t: ${if (possible) "POSSIBLE" else "IMPOSSIBLE"}")
    }
}
