fun main() {
    val test = readLine()!!.toInt()
    for (t in 1..test) {
        val a = readLine()!!
        val b = readLine()!!

        var i = 0
        var j = 0
        while (i < a.length && j < b.length) {
            while (j < b.length && a[i] != b[j]) ++j
            if (j == b.length) break
            ++i
            ++j
        }

        println("Case #$t: ${if (i == a.length) b.length - a.length else "IMPOSSIBLE"}")
    }
}
