package population;

public class Mzrkxb {

    public MinZuTeZheng[] minzu;
    public int weizhi = 0;

    public void add(String minzu2, int male_population, int female_population,
            int male_percentage, int female_percentage, double male_female_ratio) {
        minzu[weizhi] = new MinZuTeZheng(minzu2, male_population, female_population,
                male_percentage, female_percentage, male_female_ratio);
        weizhi++;
    }

    public MinZuTeZheng search_name(String name) {
        for (int i = 0; i < weizhi; i++) {
            if (minzu[i].minzu == name) {
                return minzu[i];
            }
        }
        return null;
    }

    public MinZuTeZheng search_male_population(int male_population) {
        for (int i = 0; i < weizhi; i++) {
            if (minzu[i].male_population == male_population) {
                return minzu[i];
            }
        }
        return null;
    }

    public MinZuTeZheng search_female_population(int female_population) {
        for (int i = 0; i < weizhi; i++) {
            if (minzu[i].female_population == female_population) {
                return minzu[i];
            }
        }
        return null;
    }

    public MinZuTeZheng search_male_percentage(int male_percentage) {
        for (int i = 0; i < weizhi; i++) {
            if (minzu[i].male_percentage == male_percentage) {
                return minzu[i];
            }
        }
        return null;
    }

    public MinZuTeZheng search_female_percentage(int female_percentage) {
        for (int i = 0; i < weizhi; i++) {
            if (minzu[i].female_percentage == female_percentage) {
                return minzu[i];
            }
        }
        return null;
    }

    public int sum_male_population() {
        int sum = 0;
        for (int i = 0; i < weizhi; i++) {
            sum = sum + minzu[i].male_population;
        }
        return sum;
    }

    public int sum_female_population() {
        int sum = 0;
        for (int i = 0; i < weizhi; i++) {
            sum = sum + minzu[i].female_population;
        }
        return sum;
    }

    public void delete(int location) {
        for (int i = location; i < weizhi - 1; i++) {
            minzu[i].change(minzu[i + 1]);
        }
        weizhi--;
    }

    public void sort_male_population() {
        for (int i = 0; i < weizhi - 1; i++) {
            for (int j = 0; j < weizhi - 1; j++) {
                if (minzu[j].male_population > minzu[j + 1].male_population) {
                    MinZuTeZheng k = new MinZuTeZheng();
                    k.change(minzu[j]);
                    minzu[j].change(minzu[j + 1]);
                    minzu[j + 1].change(k);
                }
            }
        }
    }

    public void sort_female_population() {
        for (int i = 0; i < weizhi - 1; i++) {
            for (int j = 0; j < weizhi - 1; j++) {
                if (minzu[j].female_population > minzu[j + 1].female_population) {
                    MinZuTeZheng k = new MinZuTeZheng();
                    k.change(minzu[j]);
                    minzu[j].change(minzu[j + 1]);
                    minzu[j + 1].change(k);
                }
            }
        }
    }

    public void sort_male_percentage() {
        for (int i = 0; i < weizhi - 1; i++) {
            for (int j = 0; j < weizhi - 1; j++) {
                if (minzu[j].male_percentage > minzu[j + 1].male_percentage) {
                    MinZuTeZheng k = new MinZuTeZheng();
                    k.change(minzu[j]);
                    minzu[j].change(minzu[j + 1]);
                    minzu[j + 1].change(k);
                }
            }
        }
    }

    public void sort_female_percentage() {
        for (int i = 0; i < weizhi - 1; i++) {
            for (int j = 0; j < weizhi - 1; j++) {
                if (minzu[j].female_percentage > minzu[j + 1].female_percentage) {
                    MinZuTeZheng k = new MinZuTeZheng();
                    k.change(minzu[j]);
                    minzu[j].change(minzu[j + 1]);
                    minzu[j + 1].change(k);
                }
            }
        }
    }

    public void resort_male_population() {
        for (int i = 0; i < weizhi - 1; i++) {
            for (int j = 0; j < weizhi - 1; j++) {
                if (minzu[j].male_population < minzu[j + 1].male_population) {
                    MinZuTeZheng k = new MinZuTeZheng();
                    k.change(minzu[j]);
                    minzu[j].change(minzu[j + 1]);
                    minzu[j + 1].change(k);
                }
            }
        }
    }

    public void resort_female_population() {
        for (int i = 0; i < weizhi - 1; i++) {
            for (int j = 0; j < weizhi - 1; j++) {
                if (minzu[j].female_population < minzu[j + 1].female_population) {
                    MinZuTeZheng k = new MinZuTeZheng();
                    k.change(minzu[j]);
                    minzu[j].change(minzu[j + 1]);
                    minzu[j + 1].change(k);
                }
            }
        }
    }

    public void resort_male_percentage() {
        for (int i = 0; i < weizhi - 1; i++) {
            for (int j = 0; j < weizhi - 1; j++) {
                if (minzu[j].male_percentage < minzu[j + 1].male_percentage) {
                    MinZuTeZheng k = new MinZuTeZheng();
                    k.change(minzu[j]);
                    minzu[j].change(minzu[j + 1]);
                    minzu[j + 1].change(k);
                }
            }
        }
    }

    public void resort_female_percentage() {
        for (int i = 0; i < weizhi - 1; i++) {
            for (int j = 0; j < weizhi - 1; j++) {
                if (minzu[j].female_percentage < minzu[j + 1].female_percentage) {
                    MinZuTeZheng k = new MinZuTeZheng();
                    k.change(minzu[j]);
                    minzu[j].change(minzu[j + 1]);
                    minzu[j + 1].change(k);
                }
            }
        }
    }
}
