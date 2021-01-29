package population;

public class MinZuTeZheng {

    public String minzu;
    public int male_population, female_population;
    public int male_percentage, female_percentage;
    public double male_female_ratio;

    public MinZuTeZheng(String minzu, int male_population, int female_population,
            int male_percentage, int female_percentage, double male_female_ratio) {
        this.minzu = minzu;
        this.male_population = male_population;
        this.female_population = female_population;
        this.male_percentage = male_percentage;
        this.female_percentage = female_percentage;
        this.male_female_ratio = male_female_ratio;
    }
    public void change(MinZuTeZheng t){
                this.minzu =t. minzu;
        this.male_population = t.male_population;
        this.female_population = t.female_population;
        this.male_percentage = t.male_percentage;
        this.female_percentage = t.female_percentage;
        this.male_female_ratio = t.male_female_ratio;
    }
    public MinZuTeZheng(){
        
    }

}
