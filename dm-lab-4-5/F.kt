import java.io.File
import java.io.BufferedReader
 
fun main() {
    val sc = File("isomorphism.in").bufferedReader()
    val out = File("isomorphism.out").bufferedWriter()
    out.write(if (solve(sc)) "YES" else "NO")
    out.close()
}
 
class DFA(sc: BufferedReader) {
    val n: Int
    val t: BooleanArray
    val delta: Array<IntArray>
 
    init {
        val q = sc.readLine().split(" ")
        val w = sc.readLine().split(" ")
        n = q[0].toInt()
        t = BooleanArray(n) { false }
        val m = q[1].toInt()
        val k1 = q[2].toInt()
        for (i in 0 until k1) t[w[i].toInt() - 1] = true
        delta = Array(n) { IntArray(26) { -1 } }
        for (i in 1..m) {
            val k = sc.readLine().split(" ")
            val a = k[0].toInt() - 1
            val b = k[1].toInt() - 1
            delta[a][k[2][0] - 'a'] = b
        }
    }
}
 
fun solve(sc: BufferedReader): Boolean {
    val x = DFA(sc)
    val y = DFA(sc)
    return dfs(x, y, 0, 0, BooleanArray(x.n) { false })
}
 
fun dfs(x: DFA, y: DFA, u: Int, v: Int, visited: BooleanArray): Boolean {
    visited[u] = true
    if (x.t[u] xor y.t[v]) return false
    for (i in 0..25) {
        val d1 = x.delta[u][i]
        val d2 = y.delta[v][i]
        if (d1 == -1 && d2 == -1) continue
        if (((d1 == -1) xor (d2 == -1)) || (!visited[d1] && !dfs(x, y, d1, d2, visited))) return false
    }
    return true
}
