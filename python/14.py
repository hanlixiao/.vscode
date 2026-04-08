#练习           影视


#异常类继承Exception
class MediaError(Exception):
    #创建文档”“”   “”“可以使用class.__doc__查看文档内容
    """Custom exception for media-related errors."""

    def __init__(self, message, obj):
        super().__init__(message)
        self.obj = obj

#创建影视类
class Movie:
    """Parent class representing a movie."""
    #构造函数  包含名称 日期 时长等元素
    def __init__(self, title, year, director, duration):
        #判断元素是否合理
        if not title.strip():
            raise ValueError('Title cannot be empty')
        if year < 1895:
            raise ValueError('Year must be 1895 or later')
        if not director.strip():
            raise ValueError('Director cannot be empty')
        if duration <= 0:
            raise ValueError('Duration must be positive')
        
        self.title = title
        self.year = year
        self.director = director
        self.duration = duration

    #打印函数
    def __str__(self):
        return f'{self.title} ({self.year}) - {self.duration} min, {self.director}'

#创建电视剧类并继承父类影视类
class TVSeries(Movie):
    """Child class representing an entire TV series.""" 
    #构造函数
    def __init__(self, title, year, director, duration, seasons, total_episodes):
        #使用super.__init__继承父类构造函数
        super().__init__(title, year, director, duration)
        
        #判断元素是否合理
        if seasons < 1:
            raise ValueError('Seasons must be 1 or greater')
        if total_episodes < 1:
            raise ValueError('Total episodes must be 1 or greater')
        
        self.seasons = seasons
        self.total_episodes = total_episodes
    #返回打印
    def __str__(self):
        return f'{self.title} ({self.year}) - {self.seasons} seasons, {self.total_episodes} episodes, {self.duration} min avg, {self.director}'

#创建媒体列表类
class MediaCatalogue:
    """A catalogue that can store different types of media items."""
    #构造
    def __init__(self):
        self.items = []

    #添加节目函数
    def add(self, media_item):
        #判断是否符合
        if not isinstance(media_item, Movie):
            raise MediaError('Only Movie or TVSeries instances can be added', media_item)
        self.items.append(media_item)

    #获取影视
    def get_movies(self):
        return [item for item in self.items if type(item) is Movie]

    #获取电视剧
    def get_tv_series(self):
        return [item for item in self.items if isinstance(item, TVSeries)]
    
    #打印函数
    def __str__(self):
        if not self.items:
            return 'Media Catalogue (empty)'
        
        movies = self.get_movies()
        series = self.get_tv_series()

        result = f'Media Catalogue ({len(self.items)} items):\n\n'
        if movies:
            result += '=== MOVIES ===\n'
            for i, movie in enumerate(movies, 1):
                result += f'{i}. {movie}\n'
        if series:
            result += '=== TV SERIES ===\n'
            for i, movie in enumerate(series, 1):
                result += f'{i}. {movie}\n'
        
        return result

catalogue = MediaCatalogue()


#测试
try:
    movie1 = Movie('The Matrix', 1999, 'The Wachowskis', 136)
    catalogue.add(movie1)
    movie2 = Movie('Inception', 2010, 'Christopher Nolan', 148)
    catalogue.add(movie2)

    series1 = TVSeries('Scrubs', 2001, 'Bill Lawrence', 24, 9, 182)
    catalogue.add(series1)
    series2 = TVSeries('Breaking Bad', 2008, 'Vince Gilligan', 47, 5, 62)
    catalogue.add(series2)

    print(catalogue)
except ValueError as e:
    print(f'Validation Error: {e}')
except MediaError as e:
    print(f'Media Error: {e}')
    print(f'Unable to add {e.obj}: {type(e.obj)}')
