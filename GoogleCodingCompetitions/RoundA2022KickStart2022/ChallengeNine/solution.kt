
fun main() {
    val test = readLine()!!.toInt()
    for (t in 1..test) {
        val s = readLine()!!
        val digitRemainder = s.sumOf { it - '0' } % 9
        val digitToAdd = 9 - digitRemainder
        if (digitToAdd == 9) {
            println("Case #$t: ${s.first()}0${s.drop(1)}")
        } else {
            val idx = s.indexOfFirst { (it - '0') > digitToAdd }
            if (idx == -1) {
                println("Case #$t: $s$digitToAdd")
            } else {
                println("Case #$t: ${s.take(idx)}$digitToAdd${s.drop(idx)}")
            }
        }
    }
}
