import kotlin.math.sqrt

fun Long.isPalindrome(): Boolean {
    val s = this.toString()
    return s == s.reversed()
}

fun main() {
    val test = readLine()!!.toInt()
    for (t in 1..test) {
        val n = readLine()!!.toLong()
        val sqrtn = sqrt(n.toDouble()).toLong() + 1
        var ans = 0
        for (i in 1 until sqrtn) {
            if (n % i == 0L) {
                if (i.isPalindrome()) ++ans
                if (i * i != n && (n / i).isPalindrome()) ++ans
            }
        }
        println("Case #$t: $ans")
    }
}
