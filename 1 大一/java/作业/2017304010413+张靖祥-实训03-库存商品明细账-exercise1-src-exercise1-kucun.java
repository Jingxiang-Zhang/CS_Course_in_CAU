package exercise1;

public class kucun {

    public String leibie;
    public int bianhao, zongyeci;

    public kucun(String leibie, int bianhao, int zongyeci) {
        this.leibie = leibie;
        this.bianhao = bianhao;
        this.zongyeci = zongyeci;
    }

    public String xiangmuleibie;
    public int zhanghuyeci;
    public String pinpaiguige;
    public String jiliangdanwei;

    public int getBianhao() {
        return bianhao;
    }

    public void setBianhao(int bianhao) {
        this.bianhao = bianhao;
    }

    public String getXiangmuleibie() {
        return xiangmuleibie;
    }

    public void setXiangmuleibie(String xiangmuleibie) {
        this.xiangmuleibie = xiangmuleibie;
    }

    public int getZhanghuyeci() {
        return zhanghuyeci;
    }

    public void setZhanghuyeci(int zhanghuyeci) {
        this.zhanghuyeci = zhanghuyeci;
    }

    public String getPinpaiguige() {
        return pinpaiguige;
    }

    public void setPinpaiguige(String pinpaiguige) {
        this.pinpaiguige = pinpaiguige;
    }

    public String getJiliangdanwei() {
        return jiliangdanwei;
    }

    public void setJiliangdanwei(String jiliangdanwei) {
        this.jiliangdanwei = jiliangdanwei;
    }

    public mingxishuju[] ming;
    public int weizhi = 0;

    public void add_mingxishuju(int nian, int yue, String zi, String hao, String zhaiyao,
            int jinhuo_shuliang, int jinhuo_danjia, int jinhuo_jine,
            int xiaoshou_shuliang, int xiaoshou_danjia, int xiaoshou_jine,
            int jiechun_shuliang, int jiecun_danjia, int jiecun_jine) {

        ming[weizhi] = new mingxishuju(nian, yue, zi, hao, zhaiyao,
                jinhuo_shuliang, jinhuo_danjia, jinhuo_jine,
                xiaoshou_shuliang, xiaoshou_danjia, xiaoshou_jine,
                jiechun_shuliang, jiecun_danjia, jiecun_jine);
        weizhi++;

    }

    public void delete_add_mingxishuju(int location) {
        for (int i = location; i < weizhi; i++) {
            ming[i].xiugai(ming[i + 1]);
            weizhi--;
        }
    }

    public void xiugai(int location, int nian, int yue, String zi, String hao, String zhaiyao,
            int jinhuo_shuliang, int jinhuo_danjia, int jinhuo_jine,
            int xiaoshou_shuliang, int xiaoshou_danjia, int xiaoshou_jine,
            int jiechun_shuliang, int jiecun_danjia, int jiecun_jine) {

        ming[location].nian = nian;
        ming[location].yue = yue;
        ming[location].zi = zi;
        ming[location].hao = hao;
        ming[location].zhaiyao = zhaiyao;
        ming[location].jinhuo_shuliang = jinhuo_shuliang;
        ming[location].jinhuo_shuliang = jinhuo_shuliang;
        ming[location].jinhuo_jine = jinhuo_jine;
        ming[location].xiaoshou_shuliang = xiaoshou_shuliang;
        ming[location].xiaoshou_danjia = xiaoshou_danjia;
        ming[location].xiaoshou_jine = xiaoshou_jine;
        ming[location].jiechun_shuliang = jiechun_shuliang;
        ming[location].jiecun_danjia = jiecun_danjia;
        ming[location].jiecun_jine = jiecun_jine;
    }

    public mingxishuju mingxishuju_chazhao(int yue, int nian, String zhaiyao) {
        for (int i = 0; i < weizhi; i++) {
            if (ming[i].yue == yue
                    && ming[i].nian == nian
                    && ming[i].zhaiyao == zhaiyao) {
                return ming[i];
            }
        }
        return null;
    }

    public int mingxishuju_jishu_shuliang() {
        int shu = 0;
        for (int i = 0; i < weizhi; i++) {
            shu = shu + ming[i].jiechun_shuliang;
        }
        return shu;
    }

    public int mingxishuju_jishu_danjia() {
        int shu = 0;
        for (int i = 0; i < weizhi; i++) {
            shu = shu + ming[i].jiecun_danjia;
        }
        return shu;
    }

    public int mingxishuju_jishu_jine() {
        int shu = 0;
        for (int i = 0; i < weizhi; i++) {
            shu = shu + ming[i].jiecun_jine;
        }
        return shu;
    }

    public int sum_jinhuo() {
        int sum = 0;
        for (int i = 0; i < weizhi; i++) {
            sum = sum + ming[i].jinhuo_jine;
        }
        return sum;
    }

    public int sum_xiaoshou() {
        int sum = 0;
        for (int i = 0; i < weizhi; i++) {
            sum = sum + ming[i].xiaoshou_jine;
        }
        return sum;
    }

    public int sum_jiechu() {
        int sum = 0;
        for (int i = 0; i < weizhi; i++) {
            sum = sum + ming[i].jiecun_jine;
        }
        return sum;
    }
}
