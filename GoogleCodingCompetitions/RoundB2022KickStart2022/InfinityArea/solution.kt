import kotlin.math.PI

fun main() {
    val test = readLine()!!.toInt()
    for (t in 1..test) {
        val (R, A, B) = readLine()!!.split(" ").map { it.toLong() }
        var right = true
        var ans = 0.0
        var radius = R
        while (radius != 0L) {
            ans += radius * radius
            if (right) {
                radius *= A
            } else {
                radius /= B
            }
            right = !right
        }
        println("Case #$t: ${ans * PI}")
    }
}
