package exercise1;

public class mingxishuju {
    public int nian,yue;
    public String zi,hao;
    public String zhaiyao;
    public int jinhuo_shuliang,jinhuo_danjia,jinhuo_jine;
    public int xiaoshou_shuliang,xiaoshou_danjia,xiaoshou_jine;
    public int jiechun_shuliang,jiecun_danjia,jiecun_jine;
    public mingxishuju(int nian,int yue,String zi,String hao,String zhaiyao,
            int jinhuo_shuliang,int jinhuo_danjia,int jinhuo_jine  ,
            int xiaoshou_shuliang,int xiaoshou_danjia,int xiaoshou_jine,
            int jiechun_shuliang,int jiecun_danjia,int jiecun_jine){
         
        this.nian=nian;this.yue=yue;
        this.zi=zi;this.hao=hao;
        this.zhaiyao=zhaiyao;
        this.jinhuo_shuliang=jinhuo_shuliang;this.jinhuo_shuliang=jinhuo_shuliang;this.jinhuo_jine=jinhuo_jine;
        this.xiaoshou_shuliang=xiaoshou_shuliang;this.xiaoshou_danjia=xiaoshou_danjia;this.xiaoshou_jine=xiaoshou_jine;
        this.jiechun_shuliang=jiechun_shuliang;this.jiecun_danjia=jiecun_danjia;this.jiecun_jine=jiecun_jine;
    }
    public void xiugai(mingxishuju t){
         this.nian=t.nian;this.yue=t.yue;
        this.zi=t.zi;this.hao=t.hao;
        this.zhaiyao=t.zhaiyao;
        this.jinhuo_shuliang=t.jinhuo_shuliang;this.jinhuo_shuliang=t.jinhuo_shuliang;this.jinhuo_jine=t.jinhuo_jine;
        this.xiaoshou_shuliang=t.xiaoshou_shuliang;this.xiaoshou_danjia=t.xiaoshou_danjia;this.xiaoshou_jine=t.xiaoshou_jine;
        this.jiechun_shuliang=t.jiechun_shuliang;this.jiecun_danjia=t.jiecun_danjia;this.jiecun_jine=t.jiecun_jine;
    }
}
