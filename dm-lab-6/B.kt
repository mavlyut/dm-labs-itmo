import java.io.FileReader
import java.io.FileWriter
import java.util.Scanner
import java.util.TreeSet
import java.util.Vector
 
const val name = "epsilon"
 
class Queue<T> {
    private val q = ArrayDeque<T>()
    fun push(x: T) = q.addLast(x)
    fun pop(): T = q.removeFirst()
    fun isNotEmpty() = q.isNotEmpty()
}
 
class CFG(sc: Scanner) {
    private val n: Int = sc.nextInt()
    private val start: Int = sc.next()[0] - 'A'
    private val rules = Array(26) { TreeSet<String>() }
    private val allRules = Vector<Pair<Int, Array<Int>>>()
    private val allNotTerminals = TreeSet<Int>()
    init {
        allNotTerminals.add(start)
        for (i in 0 until n) {
            val nt = sc.next()[0] - 'A'
            allNotTerminals.add(nt)
            val rhs = sc.nextLine().substring(3).trim()
            var fl = false
            for (c in rhs) {
                if (c in 'A'..'Z') allNotTerminals.add(c - 'A')
                else fl = true
            }
            rules[nt].add(rhs)
            var r = rhs.filter { it in 'A'..'Z' }.map { it - 'A' }.toTypedArray()
            if (fl) r = r.plus(-1)
            allRules.add(Pair(nt, r))
        }
    }
    private val isGen = BooleanArray(26) { false }
    private val isUseful = BooleanArray(26) { false }
    private val counter = IntArray(allRules.size) { allRules[it].second.size }
    private val isEpsilon = BooleanArray(26) { false }
    private val concernedRules = Array(26) { Vector<Int>() }
    init {
        for (i in allRules.indices) {
            for (j in allRules[i].second) {
                if (j != -1) concernedRules[j].add(i)
            }
        }
    }
 
    private fun getEps() {
        val q = Queue<Int>()
        for (i in counter.indices) if (counter[i] == 0) {
            isEpsilon[allRules[i].first] = true
            q.push(allRules[i].first)
        }
        while (q.isNotEmpty()) {
            val tmp = q.pop()
            for (i in concernedRules[tmp]) {
                if (--counter[i] == 0) {
                    q.push(allRules[i].first)
                    isEpsilon[allRules[i].first] = true
                }
            }
        }
    }
 
    private fun getGens() {
        var changes = true
        while (changes) {
            changes = false
            for (i in 0..25) {
                if (isGen[i]) continue
                for (rule in rules[i]) {
                    var fl = true
                    for (j in rule) {
                        if (j in 'A'..'Z') fl = fl and isGen[j - 'A']
                        if (!fl) break
                    }
                    if (fl) {
                        isGen[i] = true
                        changes = true
                        break
                    }
                }
            }
        }
    }
 
    private fun getUseful(u: Int) {
        if (u !in 0..25) return
        if (isUseful[u] && isGen[u]) return
        isUseful[u] = true
        for (rule in rules[u]) {
            var fl = true
            for (j in rule) {
                if (j in 'A'..'Z') fl = fl and isGen[j - 'A']
                if (!fl) break
            }
            if (fl) {
                for (j in rule) getUseful(j - 'A')
            }
        }
    }
 
    fun solveC(): Array<Char> {
        getGens()
        getUseful(start)
        val ans = Vector<Char>()
        for (i in allNotTerminals) {
            if (!isUseful[i] || !isGen[i]) ans.add(Char(i + 'A'.code))
        }
        return ans.toTypedArray()
    }
 
    fun solveB(): Array<Char> {
        getEps()
        val ans = ArrayList<Int>()
        for (i in 0..25) if (isEpsilon[i]) ans.add(i)
        ans.sort()
        return ans.map { Char(it + 'A'.code) }.toTypedArray()
    }
 
}
 
fun main() {
    val sc = Scanner(FileReader("$name.in"))
    val out = FileWriter("$name.out")
    out.write(CFG(sc).solveB().joinToString(" "))
    out.close()
}

