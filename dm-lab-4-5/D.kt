import java.io.FileReader
import java.io.FileWriter
import java.util.Scanner
 
const val MOD = 1_000_000_000 + 7
 
fun main() {
    val sc = Scanner(FileReader("problem4.in"))
    val out = FileWriter("problem4.out")
    val n = sc.nextInt()
    val m = sc.nextInt()
    val k = sc.nextInt()
    val l = sc.nextInt()
    val t = IntArray(k) { sc.nextInt() - 1 }
    var matrix = Array(n) { LongArray(n) { 0L } }
    for (i in 0 until m) {
        val a = sc.nextInt() - 1
        val b = sc.nextInt() - 1
        sc.next()
        matrix[a][b]++
    }
    matrix = pow(Matrix(matrix), l).matrix
//    println(matrix.joinToString("\n") { i -> i.joinToString(" ") } )
    var res = 0L
    for (i in t) res = (res + matrix[0][i]) % MOD
    out.write(res.toString())
    out.close()
}
 
fun pow(m: Matrix, l: Int): Matrix {
    if (l == 1) return m
    if (l % 2 == 0) {
        return pow(m.mul(m), l / 2)
    }
    return pow(m, l - 1).mul(m)
}
 
class Matrix {
    val matrix: Array<LongArray>
    private val n: Int
    private val m: Int
 
    constructor(n: Int, m: Int) {
        this.n = n
        this.m = m
        matrix = Array(n) { LongArray(m) { 0L } }
    }
 
    constructor(a: Array<LongArray>) {
        n = a.size
        m = a[0].size
        matrix = a
    }
 
    fun mul(b: Matrix): Matrix {
        assert(m == b.n)
        val res = Matrix(n, b.m)
        for (i in 0 until n) {
            for (j in 0 until b.m) {
                for (k in 0 until m) {
                    res.matrix[i][j] = (res.matrix[i][j] + (matrix[i][k] * b.matrix[k][j]) % MOD) % MOD
                }
            }
        }
        return res
    }
}
