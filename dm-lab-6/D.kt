import java.io.FileReader
import java.io.FileWriter
import java.util.*
 
const val name = "nfc"
const val MOD1 = 1_000_000_000 + 7
 
class RightSideOfRule(val a: Char, val b: Char, val isTerm: Boolean)
 
class Solution(sc: Scanner) {
    private val n: Int = sc.nextInt()
    private val start: Int = sc.next()[0] - 'A'
    private val rules = Array(26) { Vector<RightSideOfRule>() }
    private val dp = Array(26) { Array(200) { IntArray(200) { -1 } } }
 
    init {
        for (i in 0 until n) {
            val nt = sc.next()[0] - 'A'
            val str = sc.nextLine().substring(3).trim()
            val rhs = RightSideOfRule(str[0], if (str.length >= 2) str[1] else 'a', str.length == 1)
            rules[nt].add(rhs)
        }
    }
 
    val str: String = sc.next()
 
    private fun dp(now: Int, l: Int, r: Int): Int {
        if (dp[now][l][r] == -1) {
            var ans = 0
            for (i in rules[now].indices) {
                val cur = rules[now][i]
                if (!cur.isTerm) {
                    for (j in l + 1 until r) {
                        ans = (((dp(cur.a - 'A', l, j) + 0L) * dp(cur.b - 'A', j, r) + ans) % MOD1).toInt()
                    }
                } else {
                    if ((l + 1 == r) and (str[l] == cur.a)) {
                        ans = (ans + 1) % MOD1
                    }
                }
            }
            dp[now][l][r] = ans
        }
        return dp[now][l][r]
    }
 
    fun solve(): Int = dp(start, 0, str.length)
}
 
fun main() {
    val sc = Scanner(FileReader("$name.in"))
    val out = FileWriter("$name.out")
    out.write(Solution(sc).solve().toString())
    out.close()
}

